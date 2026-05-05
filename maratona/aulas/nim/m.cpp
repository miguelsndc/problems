#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

vector<pii> f(int x) {
    vector<pii> res;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int pot = 0;
            while (x % i == 0) x /= i, pot++;
            res.emplace_back(i, pot);
        }
    }
    if (x > 1) res.emplace_back(x, 1);
    return res;
}
/*
    essa eh a k so q modificada
    primo: numero de ocorrencias
    se k caras sao divisiveis pelo primo, adiciona k na pilha e k na lista de moves daquela primo
    se q caras sao divisiveis por primo^i adiciona q na pilha e q na lista de moves daquele primo
    um movimento so pode ser executada uma vez pra aquela pilha
*/
map<int, int> p, cnt;
set<int> primos;
map<int, vector<int>> moves;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    ll mx = *max_element(a.begin(), a.end());
    for (int x : a) {
        vector<pii> fat = f(x);
        for (auto [val, pot] : fat) {
            int cur = val;
            primos.insert(val);
            for (int j = 0; j < pot; j++) {
                p[val]++;
                cnt[cur]++;
                cur *= val;
            }
        }
    }
    for (int p : primos) {
        for (ll x = p; x <= mx; x *= p) {
            if (cnt.count(x) > 0) {
                moves[p].push_back(cnt[x]);
            }
        }
    }
    int nim = 0;
    for (int p: primos) {
        nim ^= (int)(moves[p].size() % 2);
    }
    cout << (nim != 0 ? "Mojtaba": "Arpa");
}