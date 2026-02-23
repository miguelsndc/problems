#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n, m; cin >> n >> m;
    vector<int> a(n), f(m);
    for (int &i: a) cin >> i, f[(i % m)]++;
    for (int i = 0; i < m; i++) {
        f[i] = min(f[i], lcm(f[i], m) / f[i]);
    }
    if (f[0] > 0) {
        cout << "YES\n";
        return;
    }
    vector dp(m, vector<int>(m));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}