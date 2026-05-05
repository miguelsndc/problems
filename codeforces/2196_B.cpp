#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> v(n + 1);
    vector<vector<int>> pos(n);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[i] = x;
        if (x < n) {
            pos[x].push_back(i);
        }
    }
    auto get = [&] (int a, int b) -> ll {
        ll c = 1ll * a * b;
        if (sz(pos[a]) > sz(pos[b])) swap(a, b);
        ll ans = 0;
        for (int x: pos[a]) {
            ans += (x + c <= n and v[x + c] == b);
            ans += (x - c >= 1 and v[x - c] == b);
        }
        if (a == b) ans /= 2;
        return ans;
    };
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j * i < n and j <= i; j++) {
            ans += get(i, j);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}