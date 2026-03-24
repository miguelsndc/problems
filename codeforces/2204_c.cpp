#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 a, b, c, m;
    cin >> a >> b >> c;
    cin >> m;
    i64 abc = lcm(lcm(a, b), c);
    i64 ab = lcm(a, b);
    i64 ac = lcm(a, c);
    i64 bc = lcm(b, c);
    i64 ans_a = 0, ans_b = 0, ans_c = 0;

//-----------------------------------
    ans_a += (m / abc) * 2;
    i64 c1 = (m / ab), c2 = (m / ac);
    if (lcm(ab, abc) == abc) {
        c1 -= (m / abc);
        ans_a += c1 * 3;
    }
    if (lcm(ac, abc) == abc) {
        c2 -= (m / abc);
        ans_a += c2 * 3;
    }
    i64 c3 = (m / a) - (m/ab) - (m/ac) + (m/abc);
    ans_a += c3 * 6;
//-----------------------------------
    c1 = c2 = c3 = 0;
    ans_b += (m / abc) * 2;
    c1 = (m / ab), c2 = (m / bc);
    if (lcm(ab, abc) == abc) {
        c1 -= (m / abc);
        ans_b += c1 * 3;
    }
    if (lcm(bc, abc) == abc) {
        c2 -= (m / abc);
        ans_b += c2 * 3;
    }
    c3 = (m / b) - (m/ab) - (m/bc) + (m/abc);
    ans_b += c3 * 6;
//-----------------------------------
    c1 = c2 = c3 = 0;
    ans_c += (m / abc) * 2;
    c1 = (m / bc), c2 = (m / ac);
    if (lcm(ac, abc) == abc) {
        c1 -= (m / abc);
        ans_c += c1 * 3;
    }
    if (lcm(bc, abc) == abc) {
        c2 -= (m / abc);
        ans_c += c2 * 3;
    }
    c3 = (m / c) - (m/bc) - (m/ac) + (m/abc);
    ans_c += c3 * 6;

    cout << ans_a << ' ' << ans_b << ' ' << ans_c << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
