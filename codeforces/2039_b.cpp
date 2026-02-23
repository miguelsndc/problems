#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) {
            cout << s[i] << s[i + 1] << '\n';
            return;
        }
    }
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] != s[i + 1] and s[i] != s[i + 2] and s[i + 1] != s[i + 2]) {
            cout << s[i] << s[i + 1] << s[i + 2] << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) dale();
}