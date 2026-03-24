#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n, k; cin >> n >> k;
    if (n > (k + 1) or (n & 1)) {
        cout << "Kilani\n";
    } else {
        cout << "Ayoub\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
