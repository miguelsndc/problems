#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    char mx; cin >> mx;
    auto c = [&] (char mx) { return (mx - 'A'); };
    vector<vector<int>> g(c(mx) + 1);
    string s; vector<bool> seen(mx);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while(getline(cin, s) and !s.empty()) {
        int a = c(s[0]), b = c(s[1]);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    function<void(int)> dfs = [&] (int u) {
        seen[u] = true;
        for (int v: g[u]) if (!seen[v]) dfs(v);
    };
    int ans = 0;
    for (int i = 0; i <= c(mx); i++) {
        if (!seen[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1; cin >> tt;
    cin.ignore();
    while(tt--) {
        dale();
        if (tt) cout << '\n';
    }
}