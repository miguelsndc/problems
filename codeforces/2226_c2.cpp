#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int l = 0, r = n + 1, ans = 0;
    multiset<int> ms{ a.begin(), a.end() };
    while (l <= r) {
        int m = (l + r) / 2;
        multiset<int> cur = ms;
        vector<int> removi;
        bool vai = true;
        for (int k = m - 1; k >= 0; k--) {
            if (cur.count(k)) {
                cur.erase(cur.find(k));
                removi.push_back(k);
            } else if (cur.size() > 0 and *cur.rbegin() >= (2 * k + 1)) {
                int val = *cur.rbegin();
                cur.erase(cur.find(val));
                removi.push_back(val);
            } else {
                vai = false;
                break;
            }
        }
        if (vai) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
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