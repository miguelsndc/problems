#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int mod = 1e9 + 7;
vector<ii> fatorar(int v) {
    vector<ii> ans;
    for (int i = 2; i * i <= v; i++) {
        if (v % i == 0) {
            int p = 0;
            while (v % i == 0) {
                v /= i;
                p++;
            }
            ans.push_back({i, p});
        }
    }
    if (v > 1) {
        ans.push_back({v, 1});
    }
    return ans;
}
ll fexp(ll a, ll b){
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 1;
    vector<bool> vis(n + 1);
    int size = 0;
    auto dfs = [&](int u) {
        while (!vis[u]) {
            vis[u] = true;
            size++;
            u = a[u];
        }
    };
    vector<int> max_exp(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            size = 0;
            dfs(i);
            for (auto [p, e]: fatorar(size)) {
                if (max_exp[p] < e) {   
                    ans = ans * fexp(fexp(p, max_exp[p]), mod - 2) % mod;
                    ans = ans * fexp(p, e) % mod;
                    max_exp[p] = e;
                }
            }
        }
    }
    cout << ans % mod;
}
