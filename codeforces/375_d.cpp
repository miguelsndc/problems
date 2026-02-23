#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define _sz(x) (int((x).size()))
const int mxn = 1e5 + 10;
int val[mxn], tin[mxn], tout[mxn], et[mxn], timer = 0, c[mxn], ans[mxn], bit[mxn], freq[mxn];
vector<int> g[mxn];
void bota(int pos, int val = 1) {
    for (int i = pos + 1; i < mxn; i += i & -i) bit[i] += val;
}
int sum(int pos) {
    if (pos < 0) return 0;
    ll s = 0;
    for (int i = pos + 1; i > 0; i -= i & -i) s += bit[i];
    return s;
}
inline int64_t hilbertOrder(int x, int y, int pow, int rotate){
    if(pow == 0) return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ( (y < hpow) ? 0 : 3) : ( (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
struct Query{
    int l, r, k, idx;
    int64_t ord;
    Query(int l, int r, int k, int idx) : l(l), r(r), idx(idx), k(k) {
        ord = hilbertOrder(l, r, 21, 0);
    }
    bool operator < (Query &other){
        return ord < other.ord;
    }
};

int get_ans(int k) {
    return sum(mxn) - sum(k - 1);
}
void add(int idx) {
    if (freq[val[idx]] > 0) bota(freq[val[idx]], -1);
    bota(++freq[val[idx]], 1);
}
void remove(int idx) {
    if (freq[val[idx]] > 0) bota(freq[val[idx]], -1);
    if (--freq[val[idx]] > 0) {
        bota(freq[val[idx]], 1);
    }
}

void mo(vector<Query> queries) {
    sort(queries.begin(), queries.end());
    int cur_l = 0, cur_r = -1;
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        ans[q.idx] = get_ans(q.k); 
    }
}

void euler(int u, int p = -1) {
    tin[u] = timer;
    et[timer++] = u;
    for (int v : g[u])
        if (v != p) {
            euler(v, u);
        }
    tout[u] = timer - 1;
}
void arrocha() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }
    euler(0);
    vector<Query> queries;
    for (int i = 0; i < n; i++) {
        val[i] = --c[et[i]];
    }
    for (int i = 0; i < m; i++) {
        int v, k; --k;
        cin >> v >> k; --v;
        queries.push_back({tin[v], tout[v], k, i});
    }
    mo(queries);
    
    for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) arrocha();
}