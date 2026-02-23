#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, q; cin >> n >> q;
    set<int> s; map<int,int> mp;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
        mp[i] = 1;
    }
    while(q--) {
        int x, y; cin >> x >> y;
        if (*s.begin() > x) {
            cout << 0 << '\n';
            continue;
        } 
        int cnt = 0;
        while(!s.empty() and *s.begin() <= x) {
            int k = mp[*s.begin()];
            mp[y] += k;
            cnt += k;
            s.erase(s.begin());
        }
        cout << cnt << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}