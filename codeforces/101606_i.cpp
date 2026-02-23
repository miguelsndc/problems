#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
void dale() {
    int n; cin >> n;
    vector<int> h(n);
    for (int &i: h) cin >> i;
    int T; cin >> T;
    int cur = T % h[0], best = h[0];
    for (int i = 1; i < n; i++) {
        if (chmin(cur, T % h[i])) best = h[i];
    }
    cout << best << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}