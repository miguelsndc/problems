#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    array<int, 3> prev{a[0], b[0], c[0]}, cur = prev;
    for (int i = 1; i < n; i++) {
        cur[0] = max(prev[1], prev[2]) + a[i];
        cur[1] = max(prev[0], prev[2]) + b[i];
        cur[2] = max(prev[1], prev[0]) + c[i];
        prev = cur;
    }
    cout << *max_element(cur.begin(), cur.end());
}
