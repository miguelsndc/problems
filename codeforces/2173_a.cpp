#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dale() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int cnt = 0;
    int acorda = 0; 
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            acorda = k;
        } else {
            if (acorda > 0) {
                acorda--;
            } else {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}