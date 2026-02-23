#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
struct base {
    ll rep[60], rank = 0;
    base() {
        memset(rep, 0, sizeof rep);
    }
    void add(ll x) {
        for (int b = 59; b >= 0; b--)
            if (x & (1ll << b)) {
                if (rep[b] == 0) {
                    rep[b] = x;
                    rank++;
                    return;
                }
                x ^= rep[b];
            }
    }
    bool depende(ll x) {
        for (int b = 59; b >= 0; b--)
            if (x & (1ll << b)) {
                if (rep[b] == 0) return false;
                x ^= rep[b];
            }
        return true;
    };

    void merge(const base& w) {
        for (int i = 0; i < 60; i++)
            if (w.rep[i]) add(w.rep[i]);
    }
};
const int mod = 998244353, maxn = 2e5 + 10;
ll pow2[maxn];
void dale() {
    pow2[0] = 1;
    for (int i = 1; i < maxn; i++) {
        pow2[i] = (2 * pow2[i - 1]) % mod;
    }
    base caras;
    int tamanho = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll tipo, x;
        cin >> tipo >> x;
        if (tipo == 1) {
            caras.add(x);
            tamanho++;
        } else {
            if (!caras.depende(x)) {
                cout << 0 << "\n";
            } else {
                cout << pow2[max(0ll, tamanho - caras.rank)] << '\n';
            }
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}