#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
void dale() {
    int n, q; cin >> n >> q;
    vector<int> x(q), l(q), r(q);
    for (int i = 0; i < q; i++) cin >> x[i] >> l[i] >> r[i];
    auto simula = [&] (int del = -1) {
        vector<tuple<int,int,int>> eventos;
        for (int i = 0; i < q; i++) {
            if (i == del) continue;
            eventos.push_back({l[i], 0, x[i]});
            eventos.push_back({r[i] + 1, 1, x[i]});
        }
        sort(eventos.begin(), eventos.end());
        vector<int> alugados(n + 1);
        bool ok = true;
        for (auto [t, abrir, x]: eventos) {
            if (!abrir) {
                if (alugados[x]) {
                    ok = false;
                    break;
                } else {
                    alugados[x] = true;
                }
            } else {
                alugados[x] = false;
            } 
        }
        return ok;
    };
    bool ok = simula();
    for (int i = 0; i < q; i++) ok |= simula(i);
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}