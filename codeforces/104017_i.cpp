#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()
/*
    | u - v | <= min(pu, pv)

    fixa um u, buscar caras com p em [u - pu, u - 1] e [u + 1, u + pu]

    v tbm tem q alcançar u

    a direita:
        v - u <= pv
        v - pv <= u
    a esquerda:
        u - v <= pv
        v - u >= -pv
        v + pv >= u

    b.b na seg: acha todos os caras q satisfazem O(caras * log)
*/
const int inf = 1e9;
struct Node {
    int min, max;
};
struct Seg {
    vector<Node> tree;
    vector<int> a;
    Seg(vector<int>& v) : tree(8 * sz(v)), a(v) { }
    void build(int l, int r, int v = 1) {
        if (l == r) {
            tree[v].min = l - a[l];
            tree[v].max = a[l] + l;
        } else {
            int mid = (l + r) / 2;
            build(l, mid, v * 2);
            build(mid + 1, r, v * 2 + 1);
            tree[v].max = max(tree[v * 2].max, tree[v * 2 + 1].max);
            tree[v].min = min(tree[v * 2].min, tree[v * 2 + 1].min);
        }
    }
    void remove(int k, int l, int r, int v = 1) {
        if (l == r) {
            tree[v].min = inf;
            tree[v].max = -inf;
        } else {
            int mid = (l + r) / 2;
            if (k <= mid)
                remove(k, l, mid, v * 2);
            else
                remove(k, mid + 1, r, v * 2 + 1);
            tree[v].max = max(tree[v * 2].max, tree[v * 2 + 1].max);
            tree[v].min = min(tree[v * 2].min, tree[v * 2 + 1].min);
        }
    }
    // v - pv <= u
    void get_right(vector<int>& res, int u, int start, int end, int l, int r,
                   int v = 1) {
        if (l > end or r < start or tree[v].min > u) return;
        if (start == end) {
            res.push_back(start);
            return;
        }
        int mid = (start + end) / 2;
        get_right(res, u, start, mid, l, r, v * 2);
        get_right(res, u, mid + 1, end, l, r, v * 2 + 1);
    }
    // v + pv >= u
    void get_left(vector<int>& res, int u, int start, int end, int l, int r,
                   int v = 1) {
        if (l > end or r < start or tree[v].max < u) return;
        if (start == end) {
            res.push_back(start);
            return;
        }
        int mid = (start + end) / 2;
        get_left(res, u, start, mid, l, r, v * 2);
        get_left(res, u, mid + 1, end, l, r, v * 2 + 1);
    }
};
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    Seg seg(p);
    seg.build(1, n);
    vector<int> dist(n + 1, inf);
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    seg.remove(a, 1, n);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == b) break;
        vector<int> vizinhos;
        // direita: [u + 1, u + p[u]]
        int lo = u + 1;
        int hi = min(n, u + p[u]);
        if (lo <= hi) seg.get_right(vizinhos, u, 1, n, lo, hi);
        lo = max(1, u - p[u]);
        hi = u - 1;
        if (lo <= hi) seg.get_left(vizinhos, u, 1, n, lo, hi);
        for (int v: vizinhos) {
            dist[v] = dist[u] + 1;
            q.push(v);
            seg.remove(v, 1, n);
        }
    }
    cout << dist[b] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
