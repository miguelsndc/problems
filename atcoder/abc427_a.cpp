#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i == (int)(s.size()) / 2) {
            continue;
        } else {
            cout << s[i];
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}