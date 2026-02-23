#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    vector<int> a(10);
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    map<int,int> cnt;
    for (int &x: a) {
        for (int p = 2; p * p <= x; p++) {
            while(x % p == 0) {
                x /= p;
                cnt[p]++;
            }
        }
        if (x > 1) cnt[x]++;
    }
    ll ans = 1;
    for (auto [val, c]: cnt) {
        ans *= ((c + 1) % 10) % 10;
        ans %= 10;
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}