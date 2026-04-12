#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
/*
    existe pelo menos 1 anagrama irredutivel
     = !(todos os anagramas sao redutiveis) = quando ?
     - todas as letra sao iguais
     - i.e se a ps de frequencia tiver um ponto i < n onde todas as frequencias
   batem é redutivel
     - todas as letras iguais ? chute
*/
const int ms = 2e5 + 10;
int pre[ms][26];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = sz(s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            pre[i + 1][j] = pre[i][j] + ((int)(s[i] - 'a') == j);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes\n";
            continue;
        }
        int distinct = 0;
        for (int c = 0; c < 26; c++) {
            if (pre[r][c] - pre[l - 1][c] > 0) {
                distinct++;
            }
        }
        if (distinct > 2) {
            cout << "Yes\n";    
            continue;
        }
        if (distinct == 2) {
            if (s[l - 1] != s[r - 1]) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
        }
    }
}
