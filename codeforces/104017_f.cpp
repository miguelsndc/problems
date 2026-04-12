#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> R(m), W(m);
    int mxr = 0, mxw = 0;
    for (int i = 0; i < m; i++) {
        cin >> R[i] >> W[i];
        mxr = max(mxr, R[i]);
        mxw = max(mxw, W[i]);
    }
    if (mxr + mxw > n) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int i = 0; i < mxr; i++) cout << "R"; 
    for (int i = 0; i < mxw; i++) cout << "W"; 
    for (int i = mxr + mxw + 1; i <= n; i++) cout << "W";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
