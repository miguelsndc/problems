#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using mat = vector<vector<ll>>;
ll inf = 4e18;
mat min_plus_mult(mat& A, mat& B, int n) {
    mat C(n, vector<ll>(n, inf));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    return C;
}
mat fexp(mat m, ll k, int n) {
    mat R(n, vector<ll>(n, inf));
    for (int i = 0; i < n; i++) R[i][i] = 0;
    while (k > 0) {
        if (k & 1) R = min_plus_mult(R, m, n);
        m = min_plus_mult(m, m, n);
        k /= 2;
    }
    return R;
}
void dale() {
    int n, k; cin >> n >> k;
    mat A(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> A[i][j];

    mat result = fexp(A, k, n);
    for (int s = 0; s < n; s++)
        cout << result[s][s] << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
}