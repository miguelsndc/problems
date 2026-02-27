#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void ja_avisei_vai_dar_merda_isso_ai() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &i: h) cin >> i;
    vector<int> dp(n, 1e9 + 1);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i - 2 >= 0) 
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1];
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;  // cin >> tt;
    while (tt--) ja_avisei_vai_dar_merda_isso_ai();
}

// pare antes de submitar pra revisar, antes -5 minutos revisando do q -10 de um
// wa; escreve no papel e fala em voz alta imbecil, e nunca esquecer: dp, busca
// binaria, olhar bit a bit, complemento, exchange arguments e responder offline