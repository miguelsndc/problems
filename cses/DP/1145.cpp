#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x).size()

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    for (auto &y: x) cin >> y;
    vector<int> tail;
    for (int val: x) {
        auto it = lower_bound(begin(tail), end(tail), val);
        if (it == end(tail)) {
            tail.push_back(val);
        } else {
            *it = val;
        }
    }
    cout << tail.size() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
