#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> users(n), atividades(m);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int at;
            cin >> at;
            --at;
            users[i].push_back(at);
            atividades[at].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) sort(users[i].begin(), users[i].end());
    for (int i = 0; i < m; i++) sort(atividades[i].begin(), atividades[i].end(), [&](int u, int v) {
        return users[u].size() < users[v].size();
    });
    int p = 0;
    vector<int> mark(m);
    set<ll> memo;
    auto subset = [&] (int u, int v) {
        ll key = ((ll)u << 32) | v;
        if (memo.count(key)) return true;
        memo.insert(key);
        p++;
        for (int x: users[u]) mark[x] = p;
        for (int x: users[v]) if (mark[x] != p) return false;
        return true;
    };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j + 1 < sz(atividades[i]); j++) {
            int u = atividades[i][j + 1];
            int v = atividades[i][j];
            if (!subset(u, v)) {
                cout << "YES\n";
                cout << atividades[i][j] + 1 << " " << atividades[i][j + 1] + 1 << '\n';
                return;
            }
        }
    }
    cout << "NO\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}