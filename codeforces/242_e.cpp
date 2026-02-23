#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int len = 400, sz = (n + len - 1) / len;
    vector<ll> b(sz), lazy(sz), cnt(sz);
    vector<vector<ll>> freq(sz, vector<ll>(20));
    for (int i = 0; i < n; i++) {
        b[i / len] += a[i];
        cnt[i / len]++;
        for (int bit = 0; bit < 20; ++bit) {
            if (a[i] & (1 << bit)) {
                freq[i / len][bit]++;
            }
        }
    }
    int m;
    cin >> m;
    auto pega = [&](int bl) -> pii {
        int b_start = bl * len;
        int b_end = min(n - 1, (bl + 1) * len - 1);
        return {b_start, b_end};
    };
    auto push = [&](int block) {
        if (lazy[block] == 0) return;
        auto [l, r] = pega(block);
        for (int i = l; i <= r; ++i) {
            a[i] ^= lazy[block];
        }
        lazy[block] = 0;
    };
    auto query = [&](int l, int r) -> ll {
        int bl = l / len, br = r / len;
        ll ans = 0;
        if (bl == br) {
            push(bl);
            auto [L, R] = pega(bl);
            L = max(l, L);
            int Rr = min(r, R);
            for (int i = L; i <= Rr; i++) ans += a[i];
        } else {
            push(bl);
            auto [besq_l, b_esqr] = pega(bl);
            for (int i = max(l, besq_l); i <= min(n - 1, b_esqr); i++) ans += a[i];

            for (int i = bl + 1; i <= br - 1; ++i) ans += b[i];

            push(br);
            auto [bdir_l, b_dir] = pega(br);
            for (int i = bdir_l; i <= r; i++) ans += a[i];
        }
        return ans;
    };
    auto upd_freq = [&](int block, int x) {
        ll& blck = b[block];
        lazy[block] ^= x;
        for (int i = 0; i < 20; i++) {
            if (x & (1 << i)) {
                ll& p = freq[block][i];
                blck -= (1ll << i) * 1ll * p;
                blck += (1ll << i) * 1ll * (cnt[block] - p);
                p = (cnt[block] - p);
            }
        }
    };
    auto update_namao = [&](int block, int l, int r, int x) {
        for (int i = l; i <= r; i++) {
            ll ov = a[i], nv = a[i] ^ x;
            b[block] -= ov;
            b[block] += nv;
            for (int bit = 0; bit < 20; ++bit) {
                if (ov & (1 << bit)) {
                    freq[block][bit]--;
                }
                if (nv & (1 << bit)) {
                    freq[block][bit]++;
                }
            }
            a[i] = nv;
        }
    };
    auto update = [&](int l, int r, int x) {
        int bl = l / len, br = r / len;
        if (bl == br) {
            push(bl);
            auto [L, R] = pega(bl);
            update_namao(bl, max(L, l), min(r, R), x);
        } else {
            push(bl);
            auto [besqL, besqR] = pega(bl);
            update_namao(bl, max(besqL, l), besqR, x);
            for (int i = bl + 1; i <= br - 1; ++i) upd_freq(i, x);
            push(br);
            auto [bdirL, bdirR] = pega(br);
            update_namao(br, bdirL, r, x);
        }
    };
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l, --r;
        if (t == 1) {
            cout << query(l, r) << '\n';
        } else {
            int x;
            cin >> x;
            update(l, r, x);
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    while (tt--) dale();
}