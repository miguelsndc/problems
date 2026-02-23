#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
void dale() {
    int n, M, c; cin >> n >> M >> c;
    vector<int> a(n); for (int &i: a) cin >> i;
    int mx = *max_element(a.begin(), a.end());
    int l = 0, r = mx, ans = mx;
    sort(a.begin(), a.end());
    while(l <= r) {
        int m = l + (r - l) / 2;
        int mi = 0, z = 0, w = 0;
        for (int i = 0; i < n; i++) {
            if (w == 0) {
                mi = a[i];
                w = 1; z++;
            } else if (w < c){
                if ((a[i] - mi) <= m) {
                    w++;
                } else {
                    w = 1;
                    mi = a[i];
                    z++;
                }
            } else {
                mi = a[i];
                w = 1;
                z++;
            }
        }
        if (z <= M) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
}
int main(){
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}