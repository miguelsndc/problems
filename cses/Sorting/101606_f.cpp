#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n, k;
    cin >> n >> k;
    vector dp(k + 1, vector<double>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
    }
    for (int step = 1; step <= k; step++) {
        for (int qtd = 0; qtd <= n; qtd++) {
            double up, down;
            if (qtd < n) {
                // tenho coroas pra jogar, ou ganho 1 cara ou continuo com a mesma qtd
                up = 0.5 * dp[step - 1][qtd + 1] + 0.5 * (dp[step - 1][qtd]);
            }
            if (qtd > 0) {
                // se eu jogar uma cara eu perco ou continuo com a mesma qtd
                down = 0.5 * dp[step - 1][qtd - 1] + 0.5 * dp[step - 1][qtd];
            }

            // se eu tenho coroas pra jogar quero joga-las
            if (qtd < n) {
                dp[step][qtd] =  up;
            } else {
                // se nao temo q jogar uma cara
                dp[step][qtd] = down;
            }
        }
    }
    cout << setprecision(10) << fixed << dp[k][0] << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}