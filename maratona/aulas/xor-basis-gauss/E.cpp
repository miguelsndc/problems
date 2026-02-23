#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 37;
int get(char x) {
    if (x == ' ')
        return 36;
    else if (x >= 'A' and x <= 'Z')
        return (int)(x - 'A');
    return 26 + (x - '0');
}
char revget(int x) {
    if (x == 36)
        return ' ';
    else if (x >= 0 and x <= 25)
        return char(x + 'A');
    return char(x - 26 + '0');
}
ll fexp(ll a, ll b, ll MOD) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}
vector<vector<int>> splita(int n) {
    string s;
    getline(cin, s);
    vector<int> v;
    for (char c : s) v.push_back(get(c));
    while (v.size() % n != 0) {
        v.push_back(36);
    }
    vector<vector<int>> vectors;
    vector<int> cur;
    for (char c : v) {
        cur.push_back(c);
        if (cur.size() == n) {
            vectors.push_back(cur);
            cur.clear();
        }
    }
    return vectors;
}
int gauss(int n, int m, vector<vector<ll>> &mat) {
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
        ll invp = fexp(mat[row][col], mod - 2, mod);
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
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<vector<int>> primeira = splita(n);
    vector<vector<int>> segunda = splita(n);
    vector<vector<ll>> mat;
    for (int i = 0; i < primeira.size(); i++) {
        int ind = 0;
        for (int r = 0; r < n; r++) {
            vector<ll> row(n * n + 1);
            for (int c = 0; c < n; c++) {
                row[ind] = primeira[i][c];
                ind++;
            }
            row[n * n] = segunda[i][r];
            mat.push_back(row);
        }
    }
    int posto = gauss(mat.size(), mat[0].size(), mat);
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i].back() != 0) {
            bool deu = false;
            for (int j = 0; j < n * n; j++) {
                deu |= mat[i][j] != 0;
            }
            if (!deu) {
                cout << "No solution\n";
                return;
            }
        } else {
            bool deu = true;
            for (int j = 0; j < n * n; j++) {
                deu &= mat[i][j] == 0;
            }
            if (!deu) {
                cout << "No solution\n";
                return;
            }
        }
    }
    if (posto == n * n) {
        int u = n * n;
        vector<int> ans;
        for (int j = 0; j < n * n; j++) {
            ans.push_back(mat[j][u]);
        }
        for (int i = 1; i <= ans.size(); i++) {
            cout << ans[i - 1] << " \n"[(i % n == 0)];
        }
    } else if (posto < n * n) {
        cout << "Too many solutions\n";
    } else {
        cout << "No solution\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}