#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, q;
    cin >> n >> q;
    /*
        P[i] = j
        cara mais proximo de i a direita estritamente maior i
        P[p[p[p[...]]]]
        P[n] = -1;
    */
    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> s;
    for (int i = n; i >= 1; i--) {
        while (s.size() and a[s.top()] <= a[i]) s.pop();
        p[i] = (s.size() > 0 ? s.top() : 0);
        s.push(i);
    }
    // up[i][j] = 2^i esimo ancestral de j
    vector up(20, vector<int>(n + 1));
    for (int v = 0; v <= n; v++) {
        up[0][v] = p[v];
    }
    for (int i = 1; i < 20; i++) {
        for (int v = 0; v <= n; v++) {
            if (v == 0) {
                up[i][v] = 0;
                continue;
            }
            up[i][v] = up[i - 1][up[i - 1][v]];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 1;
        int x = l;
        for (int i = 19; i >= 0; i--) {
            if (up[i][x] != 0 and up[i][x] <= r) {
                ans += (1 << i);
                x = up[i][x];
            }
        }
        cout << ans << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}