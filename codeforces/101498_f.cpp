#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
void dale() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<int> next(n);
    map<int, int> last;
    for (int i = n - 1; i >= 0; i--) {
        if (last.find(a[i]) != last.end()) {
            next[i] = last[a[i]];
        } else {
            next[i] = 2e9;
        }
        last[a[i]] = i;
    }
    set<pair<int,int>> s;
    set<int> aqui;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (aqui.count(a[i])) {
            auto it = s.lower_bound({i, a[i]});
            s.erase(it);
            s.insert({next[i], a[i]});
        } else {
            ans++;
            if (s.size() == k) {
                auto it = prev(s.end());
                aqui.erase(it->second);
                s.erase(it);
            }
            s.insert({next[i], a[i]});
            aqui.insert(a[i]);
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) dale();
    return 0;
}