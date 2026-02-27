#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void bop()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    ll ans = 0, op = 0, first = true;
    for (int x : a) {
        if (op >= x)
            continue;
        if (first)
            op = x + 100, ans += x, first = false;
        else {
            ans += (x - op); // 100
            op = x + 100;
        }
    }
    if (op < t)
        ans += (t - op);
    cout << ans << '\n';
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        bop();
}