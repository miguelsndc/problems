#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define _sz(x) (int((x).size()))
const int mxn = 5005;
int a[mxn];
int solve(int l, int r) {
    if (l > r) return 0;
    int min_el = *min_element(a + l, a + r + 1), split = -1;
    for (int i = l; i <= r; i++) {
        a[i] -= min_el;
        if (a[i] == 0) split = i;
    }
    return min({solve(l, split - 1) + solve(split + 1, r) + min_el, r - l + 1});
}
void arrocha() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << solve(0, n - 1) << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) arrocha();
}