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
    string s;
    while ((cin >> s)) {
        int n = s.size();
        vector<int> ans(n, n + 1);
        int first = 0, last = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'X') {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'X') {
                last = i;
                break;
            }
        }

        int cur = first;
        for (int i = first; i < n; i++) {
            if (s[i] == 'X') cur = i;
            ans[i] = min(ans[i], max(i - cur - 1, 0));
        }
        for (int i = last; i >= 0; i--) {
            if (s[i] == 'X') cur = i;
            ans[i] = min(ans[i], max(cur - i - 1, 0));
        }
        cout << *max_element(ans.begin(), ans.end()) << '\n';
    }
}
