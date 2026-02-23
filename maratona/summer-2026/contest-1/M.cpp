#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    map<int, ll> mp, cnt;
    cnt[a[0]]++; mp[a[0]]++;
    for (int i = 1; i < n; i++) {
        map<int, ll> nxt;
        for (auto &[x, c]: cnt) {
            nxt[__gcd(a[i], x)] += c;
        }
        nxt[a[i]]++;
        cnt = nxt;
        for (auto &[x, c]: nxt) mp[x] += c;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int x; cin >> x;
        cout << mp[x] << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}