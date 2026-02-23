#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    double score = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 0) score += 2;
        else score += (1.0 / (x + .0));
    }
    cout << setprecision(20) << fixed << score << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}