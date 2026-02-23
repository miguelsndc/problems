#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int ms = 5005;
int f[ms];
void dale() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) {
        if (f[f[i]] != f[i] and f[f[f[i]]] == i) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}