#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("fetiera.in", "r", stdin);
    int tt; cin >> tt;
    while(tt--) {
        long long n, k; cin >> n >> k;
        vector g(n, vector<long long>(n));
        for (auto &v: g) for (auto &x: v) cin >> x;
        auto cel = [&] (long long i, long long j) {
            return (1ll) * (i + 1) * (n - i) * (j + 1) * (n - j);
        };
        long long total = (n * (n + 1)) / 2 * (n * (n + 1) / 2);
        double ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                auto sub = cel(i, j);
                double prob = (double)sub / ((double)total);
                double prob_par = 1.0, prob_impar = 0.0;
                for (int bloabla = 0; bloabla < k; bloabla++) {
                    double nxt_par = prob_par * (1 - prob) + prob_impar * prob;
                    double nxt_impar = prob_par * prob + prob_impar * (1 - prob);
                    prob_par = nxt_par;
                    prob_impar = nxt_impar;
                }
                if (g[i][j]) {
                    ans += prob_par;
                } else {
                    ans += prob_impar;
                }
            }
        }
        cout << fixed << setprecision(5) << ans << '\n';
    }
}
