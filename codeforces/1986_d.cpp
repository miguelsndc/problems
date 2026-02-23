#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return a > b ? (a = b, true) : false;
}
void dale() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = ((int)(s[i] - '0'));
    if (n == 2) {
        cout << a[0] * 10 + a[1] << '\n';
        return;
    } else if (n == 3) {
        if (a[0] == 0 or a.back() == 0) {
            cout << 0 << '\n';
            return;
        } else {
            ll ans = 1e18;
            ll left = a[0] * 10 + a[1], right = a[2];
            ans = min(ans, min(left + right, left * right));
            left = a[0], right = a[1] * 10 + a[2];
            ans = min(ans, min(left + right, left * right));
            cout << ans << '\n';
            return;
        }
    } else if (count(a.begin(), a.end(), 0) > 0) {
        cout << 0 << '\n';
        return;
    }

    auto nova = [&](int pos) -> vector<int> {
        vector<int> b = a;
        int val = b[pos] * 10 + b[pos + 1];
        b[pos] = val;
        b.erase(b.begin() + pos + 1);
        return b;
    };

    ll ansans = LLONG_MAX;
    for (int i = 0; i + 1 < n; i++) {
        vector<int> res = nova(i);
        ll ans = res[0];
        for (int j = 1; j < (int)res.size(); j++) {
            ans = min(ans + res[j], ans * res[j]);
        }

        chmin(ansans, ans);
    }
    cout << ansans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) dale();
}