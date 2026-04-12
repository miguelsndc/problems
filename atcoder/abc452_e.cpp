#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<long long> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    vector<long long> pre(m + 1);
    long long sum = accumulate(b.begin(), b.end(), 0ll) % mod;
    vector<long long> d(n + 1);
    for (int j = 1; j <= min(n, m); j++) {
        long long cj = b[j] * 1ll * j % mod;
        for (int k = j; k <= n; k += j) {
            d[k] = (d[k] + cj) % mod;
        }
    }
    long long ans = 0, F = 0;
    for (int i = 1; i <= n; i++) {
        F = (F + d[i]) % mod;
        long long t1 = 1ll * i * sum % mod;
        long long cur = (t1 - F + mod) % mod;
        ans = (ans + a[i] * cur % mod) % mod;
    }
    cout << ans << '\n';
}