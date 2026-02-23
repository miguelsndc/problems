#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;
    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }
    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
void dale() {
    int n; cin >> n;
    vector<int> p(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector por_cor(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        por_cor[c[i]].push_back(p[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (por_cor[i].empty()) continue;
        ans += i * (por_cor[i].size() - lis(por_cor[i]));
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}