#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int mod = 1e9 + 7, pre_ms = 1e6 + 5, ms = 1e5 + 10;
struct matrix {
    ll mat[2][2];
    matrix() {
        memset(mat, 0, sizeof(mat));
    }
};

void add(ll &x, ll y) {
    x += y;
    if (x >= mod) x -= mod;
}

matrix init(int size) {
    return matrix();
}

vector<ll> vecmul(matrix m, vector<ll> vec, ll sz, ll mod) {
    assert(vec.size() == sz);
    vector<ll> ans(sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            ll term = (vec[j] * m.mat[i][j]) % mod; 
            add(ans[i], term);
        }
    }
    return ans;
}

matrix matmul(matrix m1, matrix m2, ll mod, ll sz) {
    matrix ans = init(sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                ll term = (1LL * (m1.mat[i][k] % mod) * (m2.mat[k][j] % mod)) % mod;
                add(ans.mat[i][j], term);
            }
        }
    }
    return ans;
}

matrix fexp(matrix p, ll b, ll mod, ll sz) {
    matrix ans = init(sz);
    for (int i = 0; i < sz; i++) ans.mat[i][i] = 1; 
    while (b) {
        if (b & 1) ans = matmul(ans, p, mod, sz);
        p = matmul(p, p, mod, sz);
        b >>= 1;
    }
    return ans;
}

ll fib(ll n) {
    if (n == 0) return 0;
    matrix m;
    m.mat[0][0] = 1; m.mat[0][1] = 1;
    m.mat[1][0] = 1; m.mat[1][1] = 0;
    matrix ans = fexp(m, n, mod, 2);
    return ans.mat[1][0]; 
}

struct Tag {
    matrix add;
    Tag() { 
        add.mat[0][0] = 1; add.mat[1][1] = 1;
    }
    Tag(ll x) { 
        matrix base;
        base.mat[0][0] = 1; base.mat[0][1] = 1;
        base.mat[1][0] = 1; base.mat[1][1] = 0;
        add = fexp(base, x, mod, 2); 
    }
    void compose(const Tag& t) { add = matmul(t.add, add, mod, 2); }
};

ll _fib[pre_ms];
ll get_fib(ll n) {
    if (n == 0) return 0;
    if (n < pre_ms) return _fib[n];
    return fib(n);
}
struct Node {
    Node() = default;
    ll f0 = 0, f1 = 0;
    Node(ll v) {
        f0 = get_fib(v + 1);
        f1 = get_fib(v);
    }
    void apply(const Tag& t) {
        vector<ll> vec = vecmul(t.add, { f0, f1 }, 2, mod);
        f0 = vec[0];
        f1 = vec[1];
    }
    static inline Node merge(Node& left, Node& right) {
        Node res;
        res.f0 = left.f0;
        add(res.f0, right.f0);
        res.f1 = left.f1;
        add(res.f1, right.f1);
        return res;
    }
};

Node seg[4 * ms]; Tag lazy[4 * ms]; ll a[ms];

void build(int l, int r, int v = 0) {
    if (l == r) {
        seg[v] = Node(a[l]);
    }
    else {
        int m = (l + r) / 2;
        build(l, m, v * 2 + 1);
        build(m + 1, r, v * 2 + 2);
        seg[v] = Node::merge(seg[v * 2 + 1], seg[v * 2 + 2]);
    }
}

void push(int v, int l, int r) {
    int left = v * 2 + 1;
    int right = v * 2 + 2;
    seg[left].apply(lazy[v]);
    lazy[left].compose(lazy[v]);
    seg[right].apply(lazy[v]);
    lazy[right].compose(lazy[v]);
    lazy[v] = Tag();
}

void update(int a, int b, int l, int r, Tag add, int v = 0) {
    if (b < l or a > r) return;
    if (a <= l and r <= b) {
        seg[v].apply(add);
        lazy[v].compose(add);
        return;
    }
    push(v, l, r);
    int m = (l + r) / 2;
    update(a, b, l, m, add, v * 2 + 1);
    update(a, b, m + 1, r, add, v * 2 + 2);
    seg[v] = Node::merge(seg[v * 2 + 1], seg[v * 2 + 2]);
}

Node query(int a, int b, int l, int r, int v = 0) {
    if (b < l or a > r) return Node();
    if (a <= l and r <= b) return seg[v];
    push(v, l, r);
    int m = (l + r) / 2;
    Node le = query(a, b, l, m, v * 2 + 1);
    Node ri = query(a, b, m + 1, r, v * 2 + 2);
    return Node::merge(le, ri);
}


void precalc() {
    _fib[1] = _fib[2] = 1;
    for (int i = 3; i < pre_ms; i++) {
        _fib[i] = _fib[i - 1];
        add(_fib[i], _fib[i - 2]);
    }
}

int main() {
    precalc();
    cin.tie(0)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(0, n - 1);
    while (m--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int l, r, x; cin >> l >> r >> x;
            --l, --r;
            update(l, r, 0, n - 1, Tag(x));
        }
        else {
            int l, r; cin >> l >> r;
            --l, --r;
            cout << query(l, r, 0, n - 1).f1 % mod << '\n';
        }
    }
}