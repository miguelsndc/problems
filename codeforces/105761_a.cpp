#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
int freq[26];
void dale() {
    string s; cin >> s;
    for (char c: s) freq[(int)(c - 'a')]++;
    bool odd = true, even = true;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            odd &= (freq[i] & 1);
            even &= (freq[i] % 2 == 0);
        }
    }
    if (odd) {
        cout << 1 << '\n';
    } else if (even) {
        cout << "0\n";
    } else {
        cout << "0/1\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}