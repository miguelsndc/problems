#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
template <typename T>
struct SparseSeg {
    struct Node {
        T val = 0;
        Node *L = NULL, *R = NULL;
        Node(T v = 0) : val(v), L(NULL), R(NULL) {}
    };
    int n;
    Node* root;
    SparseSeg(int n) : n(n) { root = new Node(NEUTRO); }
    T join(T lv, T rv) { return max(lv, rv); }
    const T NEUTRO = 0;

    ~SparseSeg() {
        clear(root);
    }

    void clear(Node* no) {
        if (!no) return;
        clear(no->L);
        clear(no->R);
        delete no;
    }

    T query(Node*& no, int l, int r, int a, int b) {
        if (b < l || r < a || no == NULL) return NEUTRO;
        if (a <= l && r <= b) return no->val;
        int m = (l + r) / 2;
        return join(query(no->L, l, m, a, b), query(no->R, m + 1, r, a, b));
    }
    void update(Node*& no, int l, int r, int pos, T v) {
        if (!no) no = new Node(NEUTRO);
        if (pos < l || r < pos) return;
        if (l == r) return (void)(no->val = v);
        int m = (l + r) / 2;

        update(no->L, l, m, pos, v);
        update(no->R, m + 1, r, pos, v);

        no->val = join(no->L->val, no->R->val);
    }

    void update(int pos, T v) { update(root, 0, n, pos, v); }
    T query(int a, int b) { return query(root, 0, n, a, b); }
};
void dale() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), d(n, 1);
    for (int& i : a) cin >> i;
    int mx = *max_element(a.begin(), a.end()) + 1;
    SparseSeg<int> seg(mx);
    for (int i = 0; i < n; i++) {
        int m = max(seg.query(0, a[i] - k), seg.query(a[i] + k, mx));
        d[i] = max(d[i], m + 1);
        seg.update(a[i], d[i]);
    }
    cout << *max_element(d.begin(), d.end());
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}