#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

const int MAX_DIGITS = 10005, MOD = 1e9 + 7;
vector<int> number;
int d;
i64 dp[MAX_DIGITS][100][2];
i64 f(int pos, int mod, int smaller) {
    if (pos == number.size()) return mod == 0;
    i64 &ans = dp[pos][mod][smaller];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i <= (smaller ? 9: number[pos]); i++) {
        bool smaller_now = (smaller or i < number[pos]);
        ans = (ans + f(pos + 1, (mod + i) % d, smaller_now)) % MOD;
    }
    return ans;
}
void solve() {
    string k; cin >> k;
    cin >> d;
    assert(d != 0);
    number.assign((int)(k.size()), 0);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < (int)(k.size()); i++) number[i] = (int)(k[i] - '0');
    i64 ans = f(0, 0, false);
    cout << (ans - 1 + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) solve();
}
