#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
void dale() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        r = i;
        if (s[i] == '1') {
            reverse(p.begin() + l, p.begin() + r);
            l = i + 1;
        }
    }
    if (l != r) {
        reverse(p.begin() + l, p.begin() + r + 1);
    }
    const int inf = 1e9;
    int mi = p[0], ma = p[0];
    vector<int> ok(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ok[i] = 1;
        else ok[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            ok[i] &= p[i] > ma;
        } else {
            ok[i] |= p[i] < ma;
        }
        mi = min(mi, p[i]);
        ma = max(ma, p[i]);
    }
    mi = p[n - 1], ma = p[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '1') {
            ok[i] &= p[i] < mi;
        } else {
            ok[i] |= p[i] > mi;
        }
        mi = min(mi, p[i]);
        ma = max(ma, p[i]);
    }

    if (all_of(ok.begin(), ok.end(), [&](const auto &v) {
        return v;
    })) {
        cout << "YES\n";
        for (int x: p) cout << x << ' ';
        cout << '\n' ;
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}