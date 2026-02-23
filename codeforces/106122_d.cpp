#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    /*
        a1 a2
        a3 a4
    */

    auto faz =[&] (int a1, int a2, int a3, int a4) {
        if (a1 == '>' and a2 == '^' and a3 == '.' and a4 == '.') return '0';
        if (a1 == 'V' and a2 == '.' and a3 == '.' and a4 == '.') return 'A';
        if (a1 == '>' and a2 == '.' and a3 == '.' and a4 == '.') return 'B';
        if (a1 == '^' and a2 == '.' and a3 == '.' and a4 == '.') return 'C';
        if (a1 == '<' and a2 == '.' and a3 == '.' and a4 == '.') return 'D';
        if (a1 == 'V' and a2 == '.' and a3 == 'V' and a4 == '.') return 'E';
        if (a1 == '>' and a2 == '.' and a3 == 'V' and a4 == '.') return 'F';
        if (a1 == '^' and a2 == '.' and a3 == 'V' and a4 == '.') return 'G';
        if (a1 == '<' and a2 == '.' and a3 == 'V' and a4 == '.') return 'H';
        if (a1 == 'V' and a2 == '.' and a3 == '>' and a4 == '.') return 'I';
        if (a1 == '>' and a2 == '.' and a3 == '>' and a4 == '.') return 'J';
        if (a1 == '^' and a2 == '.' and a3 == '>' and a4 == '.') return 'K';
        if (a1 == '<' and a2 == '.' and a3 == '>' and a4 == '.') return 'L';
        if (a1 == 'V' and a2 == '.' and a3 == '^' and a4 == '.') return 'M';
        if (a1 == '>' and a2 == '.' and a3 == '^' and a4 == '.') return 'N';
        if (a1 == '^' and a2 == '.' and a3 == '^' and a4 == '.') return 'O';
        if (a1 == '<' and a2 == '.' and a3 == '^' and a4 == '.') return 'P';
        if (a1 == 'V' and a2 == '.' and a3 == '<' and a4 == '.') return 'Q';
        if (a1 == '>' and a2 == '.' and a3 == '<' and a4 == '.') return 'R';
        if (a1 == '^' and a2 == '.' and a3 == '<' and a4 == '.') return 'S';
        if (a1 == '<' and a2 == '.' and a3 == '<' and a4 == '.') return 'T';
        if (a1 == 'V' and a2 == 'V' and a3 == '.' and a4 == '.') return 'U';
        if (a1 == 'V' and a2 == '>' and a3 == '.' and a4 == '.') return 'V';
        if (a1 == 'V' and a2 == '^' and a3 == '.' and a4 == '.') return 'W';
        if (a1 == 'V' and a2 == '<' and a3 == '.' and a4 == '.') return 'X';
        if (a1 == '>' and a2 == 'V' and a3 == '.' and a4 == '.') return 'Y';
        if (a1 == '>' and a2 == '>' and a3 == '.' and a4 == '.') return 'Z';
        if (a1 == '>' and a2 == '<' and a3 == '.' and a4 == '.') return '1';
        if (a1 == '^' and a2 == 'V' and a3 == '.' and a4 == '.') return '2';
        if (a1 == '^' and a2 == '>' and a3 == '.' and a4 == '.') return '3';
        if (a1 == '^' and a2 == '^' and a3 == '.' and a4 == '.') return '4';
        if (a1 == '^' and a2 == '<' and a3 == '.' and a4 == '.') return '5';
        if (a1 == '<' and a2 == 'V' and a3 == '.' and a4 == '.') return '6';
        if (a1 == '<' and a2 == '>' and a3 == '.' and a4 == '.') return '7';
        if (a1 == '<' and a2 == '^' and a3 == '.' and a4 == '.') return '8';
        if (a1 == '<' and a2 == '<' and a3 == '.' and a4 == '.') return '9';
        assert(false);
    };


    string a[2];
    cin >> a[0] >> a[1];
    for (int i = 0; i + 1 < a[0].size(); i += 2) {
        char r = faz(a[0][i], a[0][i + 1], a[1][i], a[1][i + 1]);
        cout << r;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}