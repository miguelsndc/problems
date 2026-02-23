#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
vector<ll> rep(60, 0); vector<vector<int>> qual(60, vector<int>()); int sz = 0;
void bota(ll x, int i) {
    map<int,int> mp;
    mp[i]++;
    for (int bit = 59; bit >= 0; bit--) if (x & (1ll << bit)) {
        if (rep[bit] == 0) {
            rep[bit] = x;
            vector<int> v;
            for (auto [c, freq]: mp) if (freq & 1) v.push_back(c);
            qual[bit] = v;
            sz++;
            return;
        }
        for (int x: qual[bit]) mp[x]++;
        x ^= rep[bit];
    }
} 
void dale() {
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bota(a[i], i);
    }
    int q; cin >> q;
    while(q--) {
        vector<int> ans(n);
        ll num; cin >> num;
        for (int bit = 59; bit >= 0; bit--) if (num & (1ll << bit)) {
                // assert(rep[bit] != 0);
                num ^= rep[bit];
                for (int x: qual[bit]) ans[x] ^= 1;
            }
        
        assert(num == 0);
        for (int x: ans) cout << x;
        cout << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}