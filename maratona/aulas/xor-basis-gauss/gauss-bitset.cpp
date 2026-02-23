#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxsz = 4096;
int placed[maxsz], posto = 0;
bitset<maxsz> basis[maxsz];
void insert(bitset<maxsz> &b, int dim) {
    for (int i = 0; i < dim; i++) if (b[i]) {
        if (!placed[i]) {
            basis[i] = b;
            placed[i] = true;
            posto++;
            break;
        } else {
            b ^= basis[i];
        }
    }
};

void dale() {
    int n, m; cin >> n >> m;
    memset(placed, 0, sizeof placed);
    vector<vector<char>> a(max(n,m), vector<char>(min(n, m)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char s; cin >> s;
            if (n < m) a[j][i] = s - '0';
            else a[i][j] = s - '0';
        }
    }
    if (n < m) swap(n, m);
    for (int i = 0; i < n; i++) {
        bitset<maxsz> b;
        for (int j = 0; j < m; j++) {
            b[j] = a[i][j];
        }
        insert(b, m);
    }
    cout << posto << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    while (tt--) {
        dale();
    }
    return 0;
}