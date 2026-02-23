#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 998244353;
ll inv(ll x) {
    ll ans = 1;
    ll b = mod - 2;
    while (b) {
        if (b & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        b >>= 1;
    }
    return ans;
}
int gauss(int n, int m, vector<vector<int>> &mat) {
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
    return posto;
};
void dale() {
    int n, m; cin >> n >> m;
    vector mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    int posto = gauss(n, m, mat);
    cout << posto << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}