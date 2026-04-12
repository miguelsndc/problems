#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())
const int BLOCK = 400;
struct query {
    int l, r, id;
    bool operator<(const query& o) const {
        int b1 = l / BLOCK, b2 = o.l / BLOCK;
        if (b1 != b2) return b1 < b2;
        return (b1 & 1) ? (r < o.r) : (r > o.r);
    }
};
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    auto get = [&] (int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin();
    };

    map<int, int> rev;
    for (int i = 0; i < n; i++) {
        rev[get(a[i])] = a[i];
        a[i] = get(a[i]);
    }

    vector<query> queries(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        queries[i] = {--l, --r, i};
    }
    vector<vector<int>> ans(q);
    vector<int> freq(n);
    sort(queries.begin(), queries.end());
    int L = 0, R = -1;
    deque<int> dq;
    for (auto &q: queries) {
        while (L > q.l) {
            dq.push_front(a[--L]);
            freq[a[L]]++;
        }
        while (R < q.r) {
            dq.push_back(a[++R]);
            freq[a[R]]++;
        }
        while (L < q.l) {
            L++;
            freq[dq.front()]--;
            dq.pop_front();
        }
        while (R > q.r) {
            R--;
            freq[dq.back()]--;
            dq.pop_back();
        }
        vector<int> v;
        for (int j = 0; j < 50 and sz(v) < 2; j++) {
            int ri = uniform(0, dq.size() - 1);
            if (freq[dq[ri]] > ((R - L + 1) / 3) and (v.empty() or dq[ri] != v.back())) {
                v.push_back(dq[ri]);
            }
        }
        if (sz(v) == 2) {
            if (v[0] > v[1]) swap(v[0], v[1]);
        }
        
        if (sz(v)) ans[q.id] = v;
        else ans[q.id] = {-1};
    }

    for (int i = 0; i < q; i++) {
        for (int x: ans[i]) cout << (x == -1? -1: rev[x]) << ' ';
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();   
}