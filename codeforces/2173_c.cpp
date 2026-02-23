#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    vector<bool> valido(n, false);
    for(int i = 0; i < n; ++i) {
        ll val = a[i];
        if (k / val > n) continue; 
        bool ok = true;
        for (ll m = val; m <= k; m += val) {
            auto it = lower_bound(a.begin(), a.end(), m);
            if (it == a.end() || *it != m) {
                ok = false;
                break;
            }
        }
        if (ok) valido[i] = true;
    }

    vector<bool> pinto = valido;
    for(int i = 0; i < n; ++i) {
        if (!valido[i]) continue;
        ll val = a[i];
        for (ll m = 2 * val; m <= k; m += val) {
            auto it = lower_bound(a.begin(), a.end(), m);
            if (it != a.end() && *it == m) {
                int idx = distance(a.begin(), it);
                if (valido[idx]) {
                    pinto[idx] = false;
                }
            }
        }
    }

    vector<ll> ans;
    vector<bool> x(n, false);
    int xcnt = 0;

    for(int i = 0; i < n; ++i) {
        if (pinto[i]) {
            ans.push_back(a[i]);
            ll val = a[i];
            for (ll m = val; m <= k; m += val) {
                auto it = lower_bound(a.begin(), a.end(), m);
                if (it != a.end() && *it == m) {
                    int idx = it - a.begin();
                    if (!x[idx]) {
                        x[idx] = true;
                        xcnt++;
                    }
                }
            }
        }
    }

    if (xcnt == n) {
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    } else {
        cout << "-1\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}