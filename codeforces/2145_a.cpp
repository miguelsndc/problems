#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        for (int i = 0; i <= 2; i++) {
            if ((n + i) % 3 == 0) {
                cout << i << '\n';
                break;
            }
        }
    }
}