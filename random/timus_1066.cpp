#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n; float a;
const int eps = 1e-6;
int gauss(int n, int m, vector<vector<float>>& mat) {
    int posto = 0;
    for (int col = 0, row = 0; col < m and row < n; col++) {
        int pivo = -1;
        for (int i = row; i < n; i++) {
            if (fabs(mat[i][col]) > eps) {
                pivo = i;
                break;
            }
        }
        if (pivo == -1) continue;
        swap(mat[row], mat[pivo]);
        float invp = mat[row][col];
        for (int j = col; j < m; j++) mat[row][j] /= invp;
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            float fac = mat[i][col];
            for (int j = col; j < m; j++) {
                mat[i][j] = (mat[i][j] - fac * mat[row][j]);
            }
        }
        row++;
        posto = row;
    }
    return posto;
};
bool check(float m) {
    vector<vector<float>> mat;
    for (int p = 0; p < n - 2; p++) {
        vector<float> line(n - 1);
        line[p] = 2;
        line[n - 2] = -2;
        if (p == 0) {
            line[n - 2] += a;
        } else {
            line[p - 1] = -1;
        }
        if (p + 1 == n - 2) {
            line[n - 2] += m;
        } else {
            line[p + 1] = -1;
        }
        mat.push_back(line);
    }
    for (auto &v: mat) {
        for (int x: v) cout << x << ' ';
        cout << '\n';
    }
    cout << "\n\n";
    gauss(mat.size(), mat[0].size(), mat);
    for (int i = 0; i < mat.size(); i++) {
        if (mat[i].back() < 0) {
            return false;
        }
    }
    return true;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n; cin >> a;
    double l = 0, r = 1e9;
    for (int i = 0; i < 200; i++) {
        double m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l << '\n';
}