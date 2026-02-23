#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<int> d(n + 1, inf), pos(n + 1, inf);
    d[0] = -inf;
    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (a[i] <= d[l]) {
            d[l] = a[i];
        }
    }
    int len = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < inf) len = i;
    }
    cout << len << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}