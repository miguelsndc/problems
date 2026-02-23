#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void print_matrix(vector<vector<char>> &mat) {
    int n = mat.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " \n"[j == n - 1];
        }
    }
}
void dale() {
    int n;
    cin >> n;
    vector mat(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    int cost = 0;
    vector done(n, vector<bool>(n));
    for (int i = 0; i * 2 < n; i++) {
        for (int j = 0; j * 2 < n; j++) {
            vector<char> M{mat[i][j], mat[n - 1 - j][i], mat[n - 1 - i][n - 1 - j], mat[j][n - 1 - i]};
            char c = *max_element(M.begin(), M.end());
            for (char e : M)
                cost += c - e;
        }
    }
    cout << cost << '\n';
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) dale();
}