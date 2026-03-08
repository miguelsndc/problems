#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    set<int> sa, sb, sc;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'A') sa.insert(i);
        if (s[i] == 'B') sb.insert(i);
        if (s[i] == 'C') sc.insert(i);
    }
    int ans = 0;
    while(sz(sa) > 0 and sz(sb) > 0 and sz(sc) > 0) {
        auto last_c = *sc.rbegin();
        auto closest_b = sb.lower_bound(last_c);
        if (closest_b == sb.begin()) { break; }
        closest_b = prev(closest_b);
        auto closest_a = sa.lower_bound(*closest_b);
        if (closest_a == sa.begin()) { break; }
        closest_a = prev(closest_a);

        ans++;
        sa.erase(closest_a);
        sb.erase(closest_b);
        sc.erase(last_c);
    }

    cout << ans;
}
