#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("files.in", "r", stdin);
    int tt; cin >> tt;
    while(tt--) {
        map<string, int> mp;
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            string s; cin >> s; int id; cin >> id;
            if (mp.count(s)) mp[s] = min(mp[s], id);
            else mp[s] = id;
        }
        vector<int> ids;
        for (auto &[_, id]: mp) ids.push_back(id);
        sort(ids.begin(), ids.end());
        for (int x: ids) cout << x << ' ';
        cout << '\n';
    }
}