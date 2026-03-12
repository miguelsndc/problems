#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) ((int)(x).size())
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int lbig = 0, rbig = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) lbig++; 
        }
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) rbig++;
        }
        ans += min(lbig, rbig);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
}
