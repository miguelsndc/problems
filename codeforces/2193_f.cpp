#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pt = pair<int, int>;
#define sz(x) ((int)((x).size()))
void dale() {
    int n, ax, ay, bx, by; cin >> n >> ax >> ay >> bx >> by;
    vector<pt> a(n); vector<int> xc(n); vector<vector<int>> per_x;
    vector<ll> ydiff;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        xc[i] = a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin(), a.end());
    sort(xc.begin(), xc.end());
    xc.erase(unique(xc.begin(), xc.end()), xc.end());
    auto get = [&] (int val) {
        return lower_bound(xc.begin(), xc.end(), val) - xc.begin() + 1;
    };
    int m = sz(xc);
    per_x.assign(m + 1 , {});
    ydiff.assign(m + 1, 0);
    for (auto &[x, y]: a) per_x[get(x)].push_back(y);
    for (int i = 1; i < sz(per_x); i++) {
        sort(per_x[i].begin(), per_x[i].end());
        ll distancia_acc = 0;
        for (int j = 0; j + 1 < sz(per_x[i]); j++) {
            distancia_acc += llabs(per_x[i][j] - per_x[i][j + 1]);
        }
        ydiff[i] = distancia_acc;
    }
    per_x[0] = {0};
    vector<pair<pt, pt>> pontas(m + 1, {{ax, ay}, {ax, ay}});
    for (int i = 1; i <= m; i++) {
        pontas[i] = {{xc[i - 1], per_x[i].back()}, {xc[i - 1], per_x[i].front()}};
    }
    auto pega = [&] (pt a, pt b) {
        return llabs(a.first - b.first) + llabs(a.second - b.second);
    };
    vector<array<ll, 2>> dp(m + 1, {0, 0});
    for (int j = 1; j <= m; j++) {
        ll d_top_top = pega(pontas[j - 1].first, pontas[j].first);
        ll d_top_bot = pega(pontas[j - 1].first, pontas[j].second);
        ll d_bot_top = pega(pontas[j - 1].second, pontas[j].first);
        ll d_bot_bot = pega(pontas[j - 1].second, pontas[j].second);
        dp[j][0] = min(dp[j - 1][0] + d_top_bot, dp[j - 1][1] + d_bot_bot) + ydiff[j];
        dp[j][1] = min(dp[j - 1][0] + d_top_top, dp[j - 1][1] + d_bot_top) + ydiff[j];
    }
    ll ans = min(dp[m][1] + pega(pontas[m].second, {bx, by}), 
                 dp[m][0] + pega(pontas[m].first, {bx, by}));
    cout << ans << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}