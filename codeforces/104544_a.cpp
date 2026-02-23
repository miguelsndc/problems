#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> divs;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            divs.push_back(i);
            if (x / i != i) divs.push_back(x / i);
        }
    }
    rg::sort(divs);
    map<ll, int> freq;
    for (int i = 0; i < n; i++) {
        ll k = __gcd(a[i], x);
        if (k > 1) freq[k]++;
    }
    auto id = [&](ll x) {
        return lower_bound(divs.begin(), divs.end(), x) - divs.begin();
    };
    const int inf = 1e9;
    vector<int> dp(sz(divs), inf);
    dp[id(x)] = 0;
    for (auto [g, f]: freq) {
        vector<int> ndp = dp; 
        for (int j = 0; j < sz(divs); j++) {
            if (dp[j] == inf) continue;
            ll curr_j = divs[j];
            int cost = dp[j]; 
            for (int c = 1; c <= f; c++) {
                ll next_j = curr_j / __gcd(curr_j, g);
                if (next_j == curr_j) break;
                curr_j = next_j;
                ndp[id(curr_j)] = min(ndp[id(curr_j)], cost + c);
            }
        }
        dp.swap(ndp); 
    }
    cout << (dp[id(1)] == inf ? -1 : dp[id(1)]) << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
}