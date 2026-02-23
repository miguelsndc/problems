#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const int VALMAX = 1e6;
#define sz(x) ((int)(x.size()))
int mobius[VALMAX];
void calc() {
    mobius[1] = -1;
    for (int i = 1; i < VALMAX; i++) {
        if (mobius[i]) {
            mobius[i] = -mobius[i];
            for (int j = 2 * i; j < VALMAX; j += i) { mobius[j] += mobius[i]; }
        }
    }
}

vector<int> divisores(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) div.push_back(n / i); 
        }
    }
    return div;
}

ll lcm (int a, int b) {
    return a / __gcd(a ,b) * b;
}

void dale() {   
    calc();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        if (mobius[i] == 0) continue;
        vector<int> div = divisores(i);
        int mmc = div[0];
        for (int i = 1; i < sz(div); i++) {
            mmc = lcm(div[i], mmc); 
        }
        ll num = 0, denom = mmc;
        for (int x: div) num += mmc / x;
        ll g = __gcd(num, denom);
        cout << i << ' ' << denom / g << "/" << num / g << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}