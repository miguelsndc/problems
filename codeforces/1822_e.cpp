#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> freq(26), mark(n);
    auto c = [&](char v) {
        return (int)(v - 'a');
    };
    ranges::for_each(s, [&](char v) { freq[c(v)]++; });
    bool more = ranges::any_of(freq, [&](int v) { return v > (n / 2); });
    if (more or n & 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> cnt(26);
    int k = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - i - 1]) {
            k++;
            cnt[c(s[i])]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > k / 2) {
            cout << cnt[i] << '\n';
            return;
        }
    }
    cout << (k + 1) / 2 << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt;
    cin >> tt;
    while (tt--) dale();
}