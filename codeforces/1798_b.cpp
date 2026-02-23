#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<vi> a(n, vi());
        set<pii> s1;
        set<int> s2;
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            while(m--) { 
                int x; cin >> x;
                a[i].push_back(x);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int x: a[i]) {
                if (!s2.count(x)) {
                    s2.insert(x);
                    s1.insert({i, x});
                }
            }
        }
        vector<int> ans(n, -1);
        while(!s1.empty()) {
            auto [id, val] = *s1.rbegin();
            s1.erase(*s1.rbegin());
            if (ans[id] == -1) {
                ans[id] = val;
            }
        }
        if (count(all(ans), -1)) {
            cout << -1 << '\n';
        } else {
            for (int x: ans) cout <<x << ' ';
            cout << '\n';
        }
    }
}