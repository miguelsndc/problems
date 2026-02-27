#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 10;
void run_case() {
    int n, k; cin >> n >> k;
    vector<int> h(n), dp(n, inf);
    for (auto &i: h) cin >> i;
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n - 1];
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) run_case();
}

// pare antes de submitar pra revisar, antes -5 minutos revisando do q -10 de um wa
// escreve no papel e fala em voz alta imbecil
// nunca esquecer: dp, busca binaria, olhar bit a bit, complemento, exchange arguments e responder offline