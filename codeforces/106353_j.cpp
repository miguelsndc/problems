#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, q; cin >> n >> k >> q;
    struct Event {
        int p, time, type, idx;
        bool operator<(const Event& other) {
            return time < other.time;
        }
    };
    vector<Event> ev;
    for (int i = 0; i < q; i++) {
        int p, l, r; cin >> p >> l >> r;
        ev.push_back({p, l, 0, i});
        ev.push_back({p, r, 1, i});
    }
    sort(ev.begin(), ev.end());
    int at_home = n;
    vector<int> ans(q);
    for (auto &[p, time, type, i]: ev) {
        if (type == 0) {
            at_home--;
        } else {
            if (at_home == 0) ans[i] = true;
            at_home++;
        }
    }
    int ok = true, keys = k;
    for (auto &[p, time, type, i]: ev) {
        if (!ans[i]) continue;
        if (type == 0) {
            keys--;
        } else {
            keys++;
        }
        ok &= (keys >= 0);
    }
    if (ok) {
        for (int x: ans) cout << x;
    } else {
        cout << "impossible\n";
    }
}