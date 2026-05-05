#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void slve() {
    int n; cin >> n;
    vector<array<int, 3>> e;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        e.push_back({a, 1, i});
        e.push_back({b + 1, -1, i});
    }
    sort(e.rbegin(), e.rend());
    ordered_set<int> s;
    /*
        sweepline dos caras chegando +1 e saindo -1
        se tu eh um segurança tu mantem uma lista dos caras q tao batendo
        na porta e dos q tao saindo da festa
        s sao os caras na festa
        pra tu ter k caras na festa tu precisa parar no kesimo sim
    */
    for (int k = 1; k <= n; k++) {
        // resolve os caras q batem na porta no tempo k e bota eles pra dentro/fora
        while(e.size() and e.back()[0] == k) {
            // entro
            if (e.back()[1] == 1) s.insert(e.back()[2]);
            // saio
            if (e.back()[1] == -1) s.erase(e.back()[2]);
            e.pop_back();
        }
        // n tem quorum
        if (s.size() < k) cout << -1 << ' ';
        // acha o kesimo sim
        else cout << *s.find_by_order(k - 1) << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    int tt = 1; // cin >> tt;
    cin.tie(0);
    while(tt--) slve();
}