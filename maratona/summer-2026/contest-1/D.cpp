#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e4 + 5;

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
    int l, r, idx;
    int64_t ord;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {
        ord = hilbertOrder(l, r, 21, 0);
    }
    Query() = default;
    bool operator < (Query &other){
        return ord < other.ord;
    }
};

const int ms = 1e6 + 5;
vector<int> freq(ms), a(maxn); int cnt = 0;

int get_ans() {
    return cnt;
}
void add(int idx) {
    if (freq[a[idx]]++ == 0) {
        cnt++;
    }
}
void remove(int idx) {
    if (--freq[a[idx]] == 0) {
        cnt--;
    }
}

void mo(vector<Query> &queries, vector<int> &ans) {
    sort(queries.begin(), queries.end());
    ans.assign(queries.size(), 0);
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
        ans[q.idx] = get_ans();  
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int q; cin >> q;
    vector<Query> queries(q); vector<int> ans(q);
    for (int i = 0; i< q; i++) {
        int l, r; cin >> l >> r; --l, --r;
        queries[i] = {l, r, i};
    }
    mo(queries, ans);
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}