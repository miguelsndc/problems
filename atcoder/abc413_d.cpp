#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n; cin >> n;
    vector<pair<ll,ll>> a(n);
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = {abs(x), x};
    }
    rg::sort(a);
    int igual = true, neg = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 1 and a[i].first != a[i - 1].first) igual = false;
        if (a[i].second < 0) neg++;
        else pos++;
    }
    if (igual and abs(neg - pos) <= 1) {
        cout << "Yes\n";
    } else {
        bool ok = true;
        for (int i = 1; i < n - 1; i++) {
            ok &= (a[i].second * a[i].second == a[i + 1].second * a[i - 1].second);
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}