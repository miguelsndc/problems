#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mod = 10007;
ll inv(ll a, ll b = mod - 2) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
vector<int> gauss(int n, int m, vector<vector<int>> &mat) {
    int posto = 0;
    for (int col = 0, row = 0; col < m and row < n; col++) {
        int pivo = -1;
        for (int i = row; i < n; i++) {
            if (mat[i][col] != 0) {
                pivo = i;
                break;
            }
        }
        if (pivo == -1) continue;
        swap(mat[row], mat[pivo]);
        ll invp = inv(mat[row][col]);
        for (int j = col; j < m; j++) mat[row][j] = (mat[row][j] * invp) % mod;
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            ll fac = mat[i][col];
            for (int j = col; j < m; j++) {
                mat[i][j] = (mat[i][j] - fac * mat[row][j]) % mod;
                if (mat[i][j] < 0) mat[i][j] += mod;
            }
        }
        row++;
        posto = row;
    }
    vector<int> sol;
    for (int i = 0; i < n; i++) {
        sol.push_back(mat[i][n]);
    }
    return sol;
};
void dale() {
    int n, d, w, l; cin >> n >> d >> w >> l;
    /* 
    0 - normal
    1 - vitoria
    2 - derrota
    */
    vector<int> tipo(n);
    for (int i = 0; i < w; i++) {
        int x; cin >> x;
        tipo[x - 1] = 1;
    }
    for (int i = 0; i < l; i++) {
        int x; cin >> x;
        tipo[x - 1] = 2;
    }
    vector<vector<int>> mat(n, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        if (tipo[i] == 0) {
            mat[i][i] = d;
            for (int face = 1; face <= d; face++) {
                int posicao = (i + face) % n;
                mat[i][posicao] = (mat[i][posicao] - 1 + mod) % mod;
            }
            mat[i][n] = 0;
        }
        else if (tipo[i] == 1) {
            mat[i][i] = 1;
            mat[i][n] = 1;
        }
        else {
            mat[i][i] = 1;
            mat[i][n] = 0;
        }
    }
    auto sol = gauss(n, n + 1, mat);
    cout << sol[0] % mod << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}