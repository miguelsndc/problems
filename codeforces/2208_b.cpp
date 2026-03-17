#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

/*

    claim: sempre pega a carta boa quando der, se nao tira a menor carta das disponiveis
    simular
*/

void solve() {
    int n, k, p, m; cin >> n >> k >> p >> m;
    deque<pair<int, int>> dq(n);
    deque<pair<int, int>> temp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        dq[i] = {x, (i + 1) == p};
    }
    int gasto = 0, ans = 0;
    while (gasto < m) {
        int  found = false, min_cost = 1e9, cara = -1;
        for (int i = 0; i < k; i++) {
            if (dq[i].second) {
                cara = i;
                found = true;
                min_cost = dq[i].first;
                break;
            } else if (dq[i].first < min_cost) {
                min_cost = dq[i].first;
                cara = i;
            }
        }   
        auto c = dq[cara];
        dq.erase(dq.begin() + cara);
        dq.push_back(c);
        if (gasto + min_cost <= m) {
            ans += found;
        }   
        gasto += min_cost;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
