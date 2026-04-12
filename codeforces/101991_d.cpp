#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("dull.in", "r", stdin);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, m;
        int k;
        cin >> n >> m;
        cin >> k;
        vector<long long> x(k), y(k);  // [k + 1] * [k + 1]
        vector<long long> vx, vy;
        /*
        
            (qtd de y distinto) x (qtd de x distinto)
        */
        vx.push_back(1);
        vx.push_back(n + 1);
        vy.push_back(1);
        vy.push_back(m + 1);
        for (int i = 0; i < k; i++) {
            cin >> x[i] >> y[i];
            vx.push_back(x[i]);
            vy.push_back(y[i]);
        }
        sort(vx.begin(), vx.end());
        vx.erase(unique(vx.begin(), vx.end()), vx.end());
        sort(vy.begin(), vy.end());
        vy.erase(unique(vy.begin(), vy.end()), vy.end());

        int p = (int)(vx.size()) - 1;
        int q = (int)(vy.size()) - 1;
        vector grid(p, vector<int>(q));
        for (int i = 0; i < k; i++) {
            int xi = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
            int yi = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
            grid[xi][yi]++;
        }
        vector ps(p, vector<int>(q));  // k * k
        long long ans = 0, outro = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                ps[i][j] = grid[i][j];
                if (i > 0) ps[i][j] += ps[i - 1][j];
                if (j > 0) ps[i][j] += ps[i][j - 1];
                if (i > 0 and j > 0) ps[i][j] -= ps[i - 1][j - 1];

                // x
                long long area = (vx[i + 1] - vx[i]) * (vy[j + 1] - vy[j]);
                if (ps[i][j] & 1) {
                    ans += area;
                } else {
                    outro += area;
                }
            }
        }
        cout << ans << ' ' << outro << '\n';
    }
}
