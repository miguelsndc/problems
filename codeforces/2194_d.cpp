#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

/*
    pra cada coluna escolhe um sufixo
    tal que a soma dos uns seja o mais proximo possivel de cnt[1] / 2
    so fazer ?
    - o tamanho dos sufixos é nao crescente
    - sempre pega tudo, o tamanho diminui por conta
*/

void slve() {
    int n, m; cin >> n >> m;
    vector g(n, vector<int>(m));
    vector mark(n, vector<int>(m));
    int cnt1 = 0;
    for (auto& v : g) for (auto& x : v) cin >> x, cnt1 += (int)(x == 1);
    int target = cnt1 / 2, cur = 0;
    for (int c = 0; c < m; c++) {
        for (int r = n - 1; r >= 0 and cur < target; r--) {
            mark[r][c] = true;
            if (cur + g[r][c] <= target) cur += g[r][c];
        }
    }
    string ans = "";
    int r = 0;
    for (int c = 0; c < m; c++) {
        while(r < n and !mark[r][c]) ans += 'D', r++;
        ans += 'R';
    }
    while(r < n) ans += 'D', r++;
    // for (int r = 0; r < n; r++) {
        // for (int c = 0; c < m; c++) cout << mark[r][c] << " \n"[c == m - 1];
    // }
    cout << 1ll * cur * (cnt1 - cur) << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}