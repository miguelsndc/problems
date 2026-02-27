#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int ms = 5e5 + 10;
const int LOG = 22;

void bop()
{
    int n;
    cin >> n;
    static int a[ms];
    static int st[LOG][ms];
    for (int i = 0; i < n; i++) cin >> a[i];
    auto build = [&]() {
        int k = 31 - __builtin_clz(n) + 1;
        iota(st[0], st[0] + n, 0);
        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                int x = st[i - 1][j];
                int y = st[i - 1][j + (1 << (i - 1))];
                st[i][j] = (a[x] > a[y] ? x : y);
            }
        }
    };
    auto query = [&](int l, int r) {
        int p = 31 - __builtin_clz(r - l + 1);
        int f = st[p][l];
        int s = st[p][r - (1 << p) + 1];
        return (a[f] > a[s] ? f : s);
    };

    function<int(int,int)> f = [&](int l, int r) -> int {
        if (r - l <= 1)
        return 0;
        int pos = query(l, r);
        int x = pos - l + f(pos + 1, r);
        int y = r - pos + f(l, pos - 1);
        return min(x, y);
    };

    build();
    cout << f(0, n - 1) << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1;
    cin >> tt;
    while (tt--)
        bop();
}