#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void solve() {
    int n; cin >> n;
    vector<int> A(2 * n), seen(n + 1), prevpar(n + 1);
    for (auto &i: A) cin >> i;
    int p = 1;
    vector<int> div;
    for (int i = 0; i < 2*n; i++) {
        if (!seen[A[i]]) seen[A[i]] = true, prevpar[A[i]] = p;
        else if (p == prevpar[A[i]]) {
            div.push_back(i);
            p ^= 1;
        }
    }
    cout << sz(div) << '\n';
    for (int x: div) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) solve();
}
