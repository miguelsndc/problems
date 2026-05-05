#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<ll, ll>

/*
    maximizar o minimo na subarvore de v = melhor resposta pra v
    pq root += min(arvore toda)

    pra um cara u com min subarvore = x e segundo menor = y
    maximiza x <=
*/

void slve() {
    int n; cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    vector tree(n, vector<int>());
    for (int i = 1; i < n; i++) {
        int pi; cin >> pi; --pi;
        tree[pi].push_back(i);
        tree[i].push_back(pi);
    }
    auto dfs = [&](auto&& self, int u, int p = -1) -> pii {
        pii value = { a[u], 1e18 };
        bool folha = true;
        for (int v : tree[u]) {
            if (v == p) continue;
            folha = false;
            auto child = self(self, v, u);
            if (child.first < value.first) {
                value.first = child.first;
                value.second = min({ child.second, value.second, value.first });
            }
            else {
                value.second = min(value.second, child.first);
            }
        }
        if (folha) {
            return value;
        }
        ll sum = (value.first + (value.second == 1e9 ? 0 : value.second));
        return { sum / 2, (sum + 1) / 2 };
        };

    ll ans = a[0], x = 1e9;
    for (int v : tree[0]) {
        auto p = dfs(dfs, v, 0);
        x = min(x, p.first);
    }
    cout << a[0] + x << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}