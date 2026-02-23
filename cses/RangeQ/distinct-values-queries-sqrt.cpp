#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

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
    bool operator < (Query &other){
        return ord < other.ord;
    }
};

const int maxn = 2e5 + 10;
vector<int> freq(maxn), a;
int distinct = 0;
int get_ans() {
    return distinct;
}
void add(int idx) {
    if (freq[a[idx]]++ == 0) distinct++;
}
void remove(int idx) {
    if (--freq[a[idx]] == 0) distinct--; 
}

void mo(vector<Query> queries, vector<int> &ans) {
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
        ans[q.idx] = get_ans();  // get answer
    }
}
void dale() {
    int n, q; cin >> n >> q;
    a.assign(n, 0);
    for (int &i: a) cin >> i;
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    map<int,int> c;
    for (int i = 0; i < b.size(); i++) {
        c[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = c[a[i]];
    }
    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        queries.emplace_back(--l, --r, i);
    }
    vector<int> ans(q);
    mo(queries, ans);
    for (int i: ans) {
        cout << i << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}