#include <bits/stdc++.h>
using namespace std;
/*
    Not Reduced- se cada digito aparece uma unica vez em cada linha e em cada coluna
    Reduced -  se a primeira linha e a primeira coluna tao sortadas e a condição
               acima é true
    No -  se nenhuma das duas acima é true
*/
const int ms = 40;
int g[ms][ms], n;
bool checa_distintos() {
    bool oklinhas = true, okcolunas = true;
    for (int i = 0; i < n; i++) {
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            if (v[g[i][j]] == 0) {
                v[g[i][j]]++;
            } else {
                return false;
            }
        }
        oklinhas &= (count(v.begin(), v.end(), 0) == 0);
    }

    for (int j = 0; j < n; j++) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            if (v[g[i][j]] == 0) {
                v[g[i][j]]++;
            } else {
                return false;
            }
        }
        oklinhas &= (count(v.begin(), v.end(), 0) == 0);
    }

    return oklinhas and okcolunas;
}

bool checa_bordas() {
    vector<int> r1, c1;
    for (int j = 0; j < n; j++) {
        r1.push_back(g[0][j]);
    }
    for (int i = 0; i < n; i++) {
        c1.push_back(g[i][0]);
    }
    bool r1sort = is_sorted(r1.begin(), r1.end());
    bool c1sort = is_sorted(c1.begin(), c1.end());
    return r1sort and c1sort; 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] >= 'A') {
                g[i][j] = (int)(s[j] - '0') - 7;
            } else {
                g[i][j] = (int)(s[j] - '0');
            }

        }
    }
    bool primeira_condicao = checa_distintos();
    bool segunda_condicao = checa_bordas();

    if (primeira_condicao and segunda_condicao) {
        cout << "Reduced";
    } else if (primeira_condicao) {
        cout << "Not Reduced";
    } else {
        cout << "No\n";
    }
}
