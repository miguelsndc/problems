#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> t(n);
    for (auto &i: t) cin >> i;
    int mx = *max_element(t.begin(), t.end());
    vector<i64> dif(mx + 1002);
    for (auto i: t) {
        dif[i]++;
        dif[i + 1000]--;
    }
    for (int i = 1; i < mx + 1002; i++) {
        dif[i] += dif[i - 1];
    }
    cout << (*max_element(dif.begin(), dif.end()) + k - 1) / k;
}
