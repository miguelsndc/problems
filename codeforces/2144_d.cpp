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
        int n; ll y;
        cin >> n >> y;
        vi a(n);
        int mx = 0;
        for (int &i: a) {
            cin >> i;
            mx = max(mx, i);
        }
        vi cnt(mx + 1);
        for (int v : a) cnt[v]++;
        vi ps(mx + 1);
        ps[0] = cnt[0];
        for (int i = 1; i <= mx; i++) {
            ps[i] = ps[i - 1] + cnt[i];
        }
        ll ans = -1e18;
        if (mx == 1) { 
            cout << n << '\n';
            continue;
        }
        for (int x = 2; x <= mx; x++) {
            ll res = 0;
            for (int price = 1; price <= mx; price++) {
                int l = x * (price - 1);
                int r = min(mx, x * price);
                if (l >= mx + 1) break;
                int c = ps[r] - (l > 0 ? ps[l] : 0);
                res += 1LL * c * price;
                res -= y * max(0, c - cnt[price]);
            }
            ans = max(ans, res);
        }
        cout << ans << '\n';
    }
}
