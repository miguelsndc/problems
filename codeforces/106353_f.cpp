#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int outro = 0, total = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        outro += a[i]; total += b[i];
    }
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (total - (outro - a[i]) <= b[i]) {
            ok = true;
            cout << i + 1 << '\n';
            break;
        }
    }
    if (!ok) cout << "impossible";
}