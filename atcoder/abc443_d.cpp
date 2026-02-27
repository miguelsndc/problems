#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
void bop() {
    int n; cin >> n;
    vector<int> R(n);
    set<ii> s;
    for (auto &i: R) cin >> i;
    ll cost = 0;
    for (int i = 0; i < n; i++) s.insert({R[i], i});
    while(!s.empty()) {
        auto [valor, id] = *s.begin();
        s.erase(*s.begin());
        vector<int> fixes;
        if (id - 1 >= 0 and abs(valor - R[id - 1]) > 1)  fixes.push_back(id - 1);
        if (id + 1 < n and abs(valor - R[id + 1]) > 1) fixes.push_back(id + 1);
        if (fixes.empty()) continue;
        for (int fid: fixes) {
            s.erase(s.find({R[fid], fid}));
            cost += (R[fid] - (valor + 1));
            R[fid] = valor + 1;
            s.insert({R[fid], fid});
        }
    }
    cout << cost << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;cin >> tt;
    while(tt--) bop();
}