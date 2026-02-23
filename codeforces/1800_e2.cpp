#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
void dale() {
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;
    vector g(n, vector<int>());
    vector<vector<int>> cc;
    for (int i = 0; i < n; i++) {
        if (i + k < n) {
            g[i].push_back(i + k);
            g[i + k].push_back(i);
        } 
        if (i + k + 1 < n) {
            g[i].push_back(i + k + 1);
            g[i + k + 1].push_back(i);
        }
    }

    vector<int> visited(n), c;
    auto collect = [&](auto &&self, int u) -> void {
        c.push_back(u);
        visited[u] = true;
        for (int v: g[u]) {
            if (visited[v]) continue;
            self(self, v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            collect(collect, i);
            cc.push_back(c);
            c.clear();
        }
    }
    bool ok = true;
    for (const auto &v: cc) {
        vector<char> cs, ct;
        for (int x: v) {
            cs.push_back(s[x]);
            ct.push_back(t[x]);
        }
        sort(all(cs));
        sort(all(ct));
        for (int i = 0; i < (int)cs.size(); i++) {
            ok &= (cs[i] == ct[i]);
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}	
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) dale();
}
