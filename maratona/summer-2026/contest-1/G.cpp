#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &[x, y]: a) cin >>x >> y;
    a.push_back({0, 0});
    sort(a.begin(), a.end());
    int L, P; cin >> L >> P;
    priority_queue<int> pq;
    int x = 0;
    for (int i = n; i >= 0; i--) {
        P -= (L - a[i].first);
        L = a[i].first;
        while (pq.size() and P < 0) P += pq.top(), pq.pop(), x++;
        if (P < 0) {
            cout << "-1\n";
            return;
        }
        pq.push(a[i].second);
    }
    if (P < 0) cout << "-1\n";
    else cout << x << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while(tt--) solve();
}