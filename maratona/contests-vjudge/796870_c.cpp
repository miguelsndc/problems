#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
const int ms = 1e6 + 20;
u64 a, b, is_prime[ms];
vector<u64> primes, caras, somas;
void crivo() {
    fill(is_prime, is_prime + ms, true);
    for (int i = 2; i < ms; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i + i; j < ms; j += i) {
                is_prime[j] = false;
            }
        }
    }
}
void segmented() {
    for (u64 p: primes) {
        if (p * p > b) break;
        u64 primeiro = (a + p - 1) / p * p;
        for (u64 i = primeiro; i <= b; i += p) {
            if (caras[i - a] % p != 0) continue;
            u64 pot = 1;
            while(caras[i - a] % p == 0) {
                caras[i - a] /= p;
                pot *= p;
            }
            somas[i - a] *= (pot * p - 1) / (p - 1);
        }
    }
}
void solve() {
    cin >> a >> b;
    for (u64 i = a; i <= b; i++) caras.push_back(i), somas.push_back(1);
    crivo();
    segmented();
    u64 ans = 0;
    for (u64 i = a; i <= b; i++) {
        if (caras[i - a] > 1) {
            somas[i - a] *= (caras[i - a] + 1);
        }
    }
    cout << accumulate(somas.begin(), somas.end(), 0ull) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
