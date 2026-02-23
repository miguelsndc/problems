#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n, q, l; cin >> n >> q >> l;
    vector<unsigned int> sobrevive(n);
    unsigned int m = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = l - 1; j >= 0; j--) {
            if (s[j] == '1') {
                sobrevive[i]|= (1 << (l - j - 1));
            }
        }
        m |= sobrevive[i];
    }
    m = ~m;
    for (int j = 31; j >= l; j--) {
        if ((m & (1 << j))) {
            m &= ~(1 << j);
        }
    }
    for (int i = 0; i < q; i++) {
        unsigned int b = 0;
        string s; cin >> s;
        for (int j = l - 1; j >= 0; j--) {
            if (s[j] == '1') {
                b |= (1 << (l - j - 1));
            }
        }
        unsigned int res = b & m;
        if (res == 0) {
            cout << "survives\n";
        } else if (res == m) {
            cout << "dies\n";
        } else {
            cout << "uncertain\n";
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}