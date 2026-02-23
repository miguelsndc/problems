#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void dale() {
    ll hp_a, hp_b, atk_a, atk_b;
    cin >> hp_a >> hp_b >> atk_a >> atk_b;
    ll orig_a = hp_a;
    ll orig_b = hp_b;
    auto get_sum = [&](ll k) {
        ll lo = 1, hi = 7e5, ans = 7e5;
        while (lo <= hi) {
            ll m = lo + (hi - lo) / 2;
            if ((m * (m + 1) / 2) >= k) {
                ans = m;
                hi = m - 1;
            }
            else {
                lo = m + 1;
            }
        }
        return ans;
        };
    ll rodada = get_sum(hp_a + hp_b);
    vector<char> ans(rodada + 1);
    ll tot = 0;
    for (int dano = rodada; dano >= 1; dano--) {
        ll sum_rest = 1LL * dano * (dano - 1) / 2;
        if (hp_a <= 0) {
            hp_b -= dano;
            ans[dano] = 'B';
            continue;
        }
        if (hp_b <= 0) {
            hp_a -= dano;
            ans[dano] = 'A';
            continue;
        }
        bool mustA = hp_a > sum_rest;
        bool mustB = hp_b > sum_rest;

        if (mustA) {
            hp_a -= dano;
            ans[dano] = 'A';
        }
        else if (mustB) {
            hp_b -= dano;
            ans[dano] = 'B';
        }
        else {
            if (atk_a > atk_b) {
                hp_a -= dano;
                ans[dano] = 'A';
            }
            else if (atk_b > atk_a) {
                hp_b -= dano;
                ans[dano] = 'B';
            }
            else {
                hp_b -= dano;
                ans[dano] = 'B';
            }
        }
    }

    ll total = 0;
    ll cur_a = orig_a;
    ll cur_b = orig_b;

    for (int i = 1; i <= rodada; i++) {
        if (cur_a > 0) total += atk_a;
        if (cur_b > 0) total += atk_b;
        if (ans[i] == 'A') cur_a -= i;
        else cur_b -= i;
    }

    cout << total << ' ';
    for (int i = 1; i <= rodada; i++)
        cout << ans[i];
    cout << '\n';

}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}
