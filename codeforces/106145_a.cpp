#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define _sz(x) (int((x).size()))
void arrocha() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int ans = 0;
    vector<pii> v;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            x++;
        } else if (x > 0) {
            v.push_back({x, i});
            x = 0;
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) arrocha();
}