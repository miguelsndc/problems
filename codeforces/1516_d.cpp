#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 1e5 + 10;
int crivo[ms], mfp[ms], nxt[ms], pos[ms], a[ms], LOG = 22;
void precalc() {
    fill(crivo, crivo + ms, 1);
    iota(mfp, mfp + ms, 0);
    crivo[0] = crivo[1] = false;
    for (int i = 2; i < ms; i++) {
        if (crivo[i]) {
            for (int j = 2 * i; j < ms; j += i) {
                crivo[j] = false;
                if(mfp[j] == j) mfp[j] = i;
            }
        }
    }
}
int main() {
    precalc();
    cin.tie(0)->sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    fill(nxt, nxt + ms, n);
    fill(pos, pos + ms, n);
    for (int l = n - 1; l >= 0; l--) {
        int k = a[l];
        int minpos = n;
        while(k > 1) {
            int fat = mfp[k];
            minpos = min(pos[fat], minpos);
            pos[fat] = l;
            while(k % fat == 0) k /= fat;
        }
        nxt[l] = min(minpos, nxt[l + 1]);
    }    
    vector<vector<int>> jump(n, vector<int>(LOG, n));
    for (int i = 0; i < n; i++) {
        jump[i][0] = nxt[i];
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i < n; i++) {
            int mid = jump[i][k - 1];
            if (mid < n) {
                jump[i][k] = jump[mid][k - 1];
            }
        }
    }
    while(q--) {
        int l, r; cin >> l >> r; --l, --r;
        int ans = 1, p = l;
        for (int k = LOG - 1; k >= 0; k--) {
            if (jump[p][k] <= r) {
                ans += (1 << k);
                p = jump[p][k];
            }
        }
        cout << ans << '\n';
    }
}