#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
template<int N>
struct XorBase {
    ll rep[N], rank = 0;
    base() {
        memset(rep, 0, sizeof rep);
    }
    void add(ll x) {
        for (int b = N - 1; b >= 0; b--)
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
        for (int b = N - 1; b >= 0; b--)
            if (x & (1ll << b)) {
                if (rep[b] == 0) return false;
                x ^= rep[b];
            }
        return true;
    };
};
void dale() {
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}
