#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int mod = 1e9 + 7;

struct Matrix {
    int n;
    vector<vector<i64>> m;
    Matrix(int n) : n(n), m(n, vector<i64>(n, 0)) {}
    Matrix mul(const Matrix& other, i64 mod) const {
        assert(n == other.n);
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!m[i][k]) continue;
                for (int j = 0; j < n; j++) {
                    res.m[i][j] = (res.m[i][j] + (m[i][k] * other.m[k][j]) % mod) % mod;
                }
            }
        }
        return res;
    }
    Matrix fexp(i64 b, i64 mod) const {
        Matrix res(n);
        for (int i = 0; i < n; i++) res.m[i][i] = 1; 
        Matrix base = *this;
        while (b > 0) {
            if (b & 1) res = res.mul(base, mod);
            base = base.mul(base, mod);
            b >>= 1;
        }
        return res;
    }
};

void solve() {
    int n; i64 k;
    cin >> n; cin >> k;
    Matrix mat(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat.m[i][j];
        }
    }
    i64 ans = 0;
    auto res = mat.fexp(k, mod);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = (ans + res.m[i][j]) % mod;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
