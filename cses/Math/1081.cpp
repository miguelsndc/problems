#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 1e6 + 10;
int freq[mxn];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; freq[x]++;
        mx = max(mx, x);
    }
    int best = 0;
    for (int d = 1; d <= mx; d++) {
        int t = 0;
        for (int m = d; m <= mx; m += d) {
            t += freq[m];
        }
        if (t > 1) {
            best = max(best, d);
        }
    }
    cout << best << '\n';
}