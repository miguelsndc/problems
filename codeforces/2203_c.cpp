#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    ll s, m; cin >> s >> m;
    ll l = 1, r = s, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        /*
            quero um array de tamanho <= mid com soma s
            e cada ai submask de m
            x submask de y entao x <= y ?
            tenho no maximo mid * m de soma
            de mid * m < s entao no
            */
        ll dif = s;
        for (int b = 62; b >= 0; b--) { 
            if (!(m & 1ll << b)) continue;
            ll val = 1ll << b;
            if (val > dif) continue;
            ll quo = min(mid, dif / val);
            dif -= quo * val;
        }
        if (dif == 0){
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}