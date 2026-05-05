#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

void slve() {
    int n, c; cin >> n >> c;
    vector<int> d(n);
    for (auto& x : d) cin >> x;
    /*
        de i pula pro proximo anuncio
        i = next[i]^k
        next[i] o cara imediatamente após o primeiro anuncio de i
        c
        a1 a2 a3 a4

        se eu to em a1
        proximo anuncio em lower(a1 + c) + 1 == upper(a1 + c)
        ps[next[i]] - i >= c
     */
    vector<int> v = d;
    for (int x : d) v.push_back(x);
    for (int i = 1; i < sz(v); i++) v[i] += v[i - 1];
    vector<int> next(2 * n, n);
    int r = 0;
    for (int l = 0; l < 2 * n; l++) {
        while (r < 2 * n and (v[r] - (l - 1 >= 0 ? v[l - 1] : 0)) < c) r++;
        next[l] = min(r + 1, 2 * n);
    }
    vector up(22, vector<int>(2 * n));
    for (int i = 0; i < 2 * n; i++) {
        up[0][i] = next[i];
    }

    for (int k = 1; k < 22; k++) {
        for (int i = 0; i < 2 * n; i++) {
            int mid = up[k - 1][i];
            if (mid < 2 * n) up[k][i] = up[k - 1][mid];
            else up[k][i] = 2 * n;
        }
    }
    for (int l = 0; l < n; l++) {
        int cur = l, ans = 0;
        for (int k = 21; k >= 0; k--) {
            if (up[k][cur] < l + n) {
                cur = up[k][cur];
                ans += (1 << k);
            }
        }
        // if (cur < l + n) ans++;
        cout << ans << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while (tt--) slve();
}