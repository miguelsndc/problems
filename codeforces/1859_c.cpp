#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n; cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int ans = 0;
    auto get = [&](vector<int> &perm) -> int {
        int cost = 0, mx =0;
        for (int i = 0; i < n; i++) {
            int k = (i + 1) * perm[i];
            cost += k;
            mx = max(mx, k);
        }
        return cost - mx;
    };
    ans = max(ans, get(p));
    for (int i = 0; i < n; i++) {
        vector<int> p2 = p;
        reverse(p2.begin() + i, p2.end());
        ans = max(ans, get(p2));
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}