#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector g(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
    }
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = (s[i] == 'A');
    }
    for (int i = 0; i < k; i++) {
        {
            vector<int> next(n, true);
            for (int i = 0; i < n; i++) for (int j: g[i]) if (!dp[j]) next[i] = false;
            swap(dp, next);
        }
        {
            vector<int> next(n, false);
            for (int i = 0; i < n; i++) for (int j: g[i]) if (dp[j]) next[i] = true;
            swap(dp, next);
        }
    }
    cout << (dp[0] ? "Alice\n" : "Bob\n");
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}