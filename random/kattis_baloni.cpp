#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    map<int, set<int>> mp;
    int mx = 0;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        mx = max(mx, h[i]);
        mp[h[i]].insert(i);
    }
    sort(h.begin(), h.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int cur = h[i];
        if (mp[cur].empty()) continue;
        int pos = -1;
        ans++;
        while(mp[cur].size()) {
            auto it = mp[cur].lower_bound(pos);
            if (it == end(mp[cur])) break;
            pos = *it;
            mp[cur--].erase(pos);
        }
    }
    cout << ans << '\n';
}
