#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n, m; cin >> n >> m;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x; char p; cin >> x; cin >> p;
        a[i] = {x, (p == 'U')};
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}