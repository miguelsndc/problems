#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void dale() {
    int n; cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        cout << a[1] << '\n';
        return;
    }
    multiset<int> ms;
    ll curr = 0;
    for (int i = 1; i <= n; i++) {
        ms.insert(a[i] + i);
        if (i & 1) {
            curr += a[i];
        } else {
            curr -= a[i];
        }
    }
    set<ll> costs{curr};
    bool alice = true;
    for (int i = 0; i < 200000; i++) {
        /*
            alice -> se ela só pode diminuir o custo ela para
            bob -> se ele só pode aumentar o custo ele para
            alice -> se encontrar custo 0 ela continua
            bob -> se encontrar custo zero para
        */
        ll nv = (*ms.rbegin()) - (*ms.begin());
        if (alice and nv >= 0) {
            curr += nv;
        } else if (!alice and nv <= 0) {
            curr += nv;
        } else {
            break;
        }
    }
    cout << curr << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}