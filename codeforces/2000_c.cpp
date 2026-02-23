#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vector<int> a(n);
        set<int> sst;
        for (int &i : a) {
            cin >> i;
            sst.insert(i);
        }
        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string s; cin >> s;
            bool ok = sst.size() <= 26;
            if (s.size() != n) {
                cout << "NO\n";
                continue;
            }
            vector<set<int>> values(26);
            for (int i = 0; i < n; i++) {
                int x = (int)(s[i] - 'a');
                values[x].insert(a[i]);
                for (int j = 0; j < 26; j++) {
                    if (x == j) continue;
                    if (values[j].count(a[i])) ok = false;
                }
            }
            for (int i = 0; i < 26; i++) {
                ok &= values[i].size() <= 1;
            }
            if (ok) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}