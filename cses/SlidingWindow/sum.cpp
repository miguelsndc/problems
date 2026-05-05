#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    vector<ll> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++) {
        v[i] = (1ll * a * v[i - 1] + b) % c; 
    }
    ll sum = 0, ans = 0;
    for (int i = 0; i < k; i++) sum += v[i];
    ans ^= sum;
    for (int i = k; i < n; i++) {
        sum += v[i];
        sum -= v[i - k];
        ans ^= sum;
    }
    cout << ans;
}