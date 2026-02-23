#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 3e5 + 10, mod = 998244353;
ll pow2[maxn];
struct Query {
    ll l, r, val, indice;
};
struct base {
    ll rep[60], rank = 0;
    base() {
        memset(rep, 0, sizeof rep);
    }
    void add(ll x) {
        for (int b = 59; b >= 0; b--)
            if (x & (1ll << b)) {
                if (rep[b] == 0) {
                    rep[b] = x;
                    rank++;
                    return;
                }
                x ^= rep[b];
            }
    }
    bool depende(ll x) {
        for (int b = 59; b >= 0; b--) if (x & (1ll << b)) {
                if (rep[b] == 0) return false;
                x ^= rep[b];
            }
        return true;
    };

    void merge(const base& w) {
        for (int i = 0; i < 60; i++) if (w.rep[i]) add(w.rep[i]);
    }
}; 

int n;
vector<ll> a;
vector<int> ans;
void solve(int l, int r, vector<Query> &queries) {
    int mid = (l + r) / 2;
    if (l == r) {
        for (Query &q : queries) {
            ans[q.indice] = (q.val == a[l] or q.val == 0);
        }
        return;
    }
    vector<Query> left, right, meio;
    for (Query &q : queries) {
        if (q.r <= mid)
            left.push_back(q);
        else if (q.l > mid)
            right.push_back(q);
        else
            meio.push_back(q);
    }

    vector<base> pre(mid - l + 1), suf(r - mid);
    for (int i = mid - 1; i >= l; i--) {
    pre[mid - l].add(a[mid]);
        pre[i - l] = pre[i + 1 - l];
        pre[i - l].add(a[i]);
    }
    if (mid < r) {
        suf[0].add(a[mid + 1]);
        for (int i = mid + 2; i <= r; i++) {
            suf[i - mid - 1] = suf[i - mid - 2];
            suf[i - mid - 1].add(a[i]);
        }
    }

    for (Query &q : meio) {
        base base_esq = pre[q.l - l];
        base base_dir = suf[q.r - mid - 1];
        base_esq.merge(base_dir);
        bool dep = base_esq.depende(q.val);
        if (!dep) {
            ans[q.indice] = 0;
        } else {
            // rank unico entao 2^nulidade
            ans[q.indice] = pow2[max((q.r - q.l + 1) - base_esq.rank, 0ll)];
        }
    }

    if (!left.empty()) solve(l, mid, left);
    if (!right.empty()) solve(mid + 1, r, right);
}
void dale() {
    pow2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pow2[i] = (2ll * pow2[i - 1]) % mod;
    }
    cin >> n;
    a.assign(n, 0);
    for (ll &i : a) cin >> i;
    int q;
    cin >> q;
    ans.assign(q, 0);
    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        ll l, r, val;
        cin >> l >> r >> val;
        queries.push_back({--l, --r, val, i});
    }
    solve(0, n - 1, queries);
    for (int x : ans) cout << x << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}