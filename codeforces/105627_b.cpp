#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] / 2) + (a[i] % 2);
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}