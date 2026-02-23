#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n; cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a.begin(), a.end());
    ll d = 0, x = 0, y = 0;
    for (auto &[s, bw, bh]: a) {
        if (x == s) {
            d += abs(y - bh);
            d += bw;
        } else {
            // anda pra baixo
            d += (s - x);
            d += y;
            d += bh;
            d += bw;
        }
        y = bh;
        x = s + bw;
    } 
    d += (y);
    d += 100 - x;
    cout << d << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}