#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int c, n; cin >> c >> n;
    vector<array<int, 3>> e;
    for (int i = 0; i < c; i++) {
        int t; cin >> t;
        e.push_back({t, 1, -1});
    }
    vector<int> ends(n), starts(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        e.push_back({a, 0, i});
        e.push_back({b, 2, i});
        ends[i] = b;
        starts[i] = a;
    }
    sort(e.begin(), e.end());
    int pairs = 0, chickens = 0;
    set<pii> unpaired;
    for (auto &[t, type, idx]: e) {
        if (type == 0) {
            unpaired.insert({ends[idx], idx});;
        } else if (type == 2) {
            if (unpaired.count({t, idx})) unpaired.erase({t, idx});
        } else if (type == 1) {
            chickens++;
            if (unpaired.size()) {
                chickens--;
                unpaired.erase(*unpaired.begin());
                pairs++;
            }
        }
    }
    cout << pairs;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    int tt = 1; // cin >> tt;
    while(tt--) slve();
}