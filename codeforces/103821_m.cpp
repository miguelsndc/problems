#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7, maxn = 1e5 + 5, inv2 = 500000004; 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    vector<ll> cnt(maxn), fat(maxn);
    for (int i = 2; i < maxn; i++) {
        for (int j = i; j < maxn; j += i) {
            cnt[j]++;
        }
    }
    fat[0] = fat[1] = 1;
    for (ll i = 2; i < maxn; i++) {
        (fat[i] = i * fat[i - 1] % mod) %= mod;
    }

    cnt[1] = 0;
    for (int i = 2; i < maxn; i++) {
        (cnt[i] += cnt[i - 1]) %= mod;
    }

    vector<ll> ans(maxn);
    for (int i = 2; i < maxn; i++) {
        ans[i] = ((fat[i] * inv2 % mod) * cnt[i]) % mod;
        ans[i] %= mod;
    }

    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        cout << ans[n] << '\n';
    }
}
