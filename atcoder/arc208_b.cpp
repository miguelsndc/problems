#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, k; cin >> n >> k;
    ll l = 0, r = 1e18 + 1, ans = 1e18 + 1;
    while(l <= r) {
        ll m = l + (r - l) / 2;
        ll sum = 0;
        ll x = m;
        for (int i = 0; i < n - 1; i++) {
            sum += (x - ((x / 2) + 1));
            x = (x / 2) + 1;
            if (x <= 2) break;
        }
        if (sum >= k) {
            r = m - 1;
            ans = m;
        } else {
            l = m + 1;
        }
    }
    vector<int> res;
    bool botei = false;
    for (int i = 0; i < n and !botei; i++) {
        if (ans == 2) botei = true;
        res.push_back(ans);
        ans = (ans / 2) + 1;
    }
    while(res.size() < n) res.push_back(2);
    reverse(res.begin(), res.end());
    for (int x: res) cout << x << ' ';
    cout << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}