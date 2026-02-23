#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
inline bool chmin(T& a, const U& b) {
    return a > b ? (a = b, true) : false;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    set<ll> s;
    unordered_map<ll, ll> mp;
    ll ans = 0;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
        auto it = s.find(x);
        ll current = 0;
        if (it != s.begin()) {
            auto pr = prev(it);
            int left = *pr;
            current = abs(x - left);
            if (!mp.count(left)) {
                mp[left] = current;
                ans += mp[left];
            } else {
                int antes = mp[left];
                if (chmin(mp[left], current)) {
                    ans -= antes;
                    ans += current;
                }
            }
        }
        if (it != prev(s.end())) {
            auto pr = next(it);
            int right = *pr;
            ll cost_right = abs(x - right);
            if (!mp.count(right)) {
                mp[right] = cost_right;
                ans += mp[right];
            } else {
                ll antes = mp[right];
                if (chmin(mp[right], cost_right)) {
                    ans -= antes;
                    ans += cost_right;
                }
            }
            chmin(current, cost_right);
        }
        mp[x] = current;
        ans += current;
        cout << ans << '\n';
    }
}