#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i != i) div.push_back(n / i);
        }
    }
    auto check = [&](int m) -> bool {
        if (m == n) return true;
        string pre, suf;
        for (int ptr = 0; ptr < m; ptr++) pre += s[ptr];
        for (int ptr = n - m; ptr < n; ptr++) suf += s[ptr];
        string period_pre, period_suf;
        for (int i = 0; i < (n / m); i++) period_pre += pre;
        for (int i = 0; i < (n / m); i++) period_suf += suf;
        int d1 = 0, d2 = 0;
        for (int i = 0; i < n; i++) {
            if (period_pre[i] != s[i]) d1++;
            if (period_suf[i] != s[i]) d2++;
        }
        return d1 <= 1 or d2 <= 1;
    };

    sort(all(div));
    for (int x : div) {
        if (check(x)) {
            cout << x << '\n';
            break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) solve();
}