#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i] - i - 1;
        // cout << c[i] << ' ';
    }
    cout << '\n';
    vector<int> tail;
    for (int i : c) {
        if(i < 0) continue;
        auto it = upper_bound(begin(tail), end(tail), i);
        if (it == end(tail)) {
            tail.push_back(i);
        } else {
            *it = i;
        }
    }
    cout << n - tail.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
