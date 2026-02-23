#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<pair<ll, ll>> prime_factorization(ll n) {
    vector<pair<ll, ll>> primes;
    for (ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0ll)
            n /= i, cnt++;
        if (cnt > 0)
            primes.push_back({cnt, i});
    }
    if (n > 1)
        primes.push_back({1, n});
    return primes;
}
void dale() {
    ll n; cin >> n;
    vector<pair<ll,ll>> primes = prime_factorization(n);
    sort(primes.rbegin(), primes.rend());
    ll z = primes[0].first, v = primes[0].second;
    vector<ll> ans(z, v);
    for (int i = 1; i < sz(primes); i++) 
        for (int j = 0; j < primes[i].first; j++) {
            ans.back() *= primes[i].second;
        }
    
    cout << sz(ans) << '\n';
    for (ll x: ans) cout << x << ' ';
    cout << '\n';
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}