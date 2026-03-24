#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto&x: a) cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int menor = 0, maior = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) maior++;
            else if (a[i] < a[j]) menor++;
        }
        cout << max(maior, menor) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
