#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        string ans(n, '+');
        int a = ranges::count(s, '0');
        int b = ranges::count(s, '1');
        int c = ranges::count(s, '2');
        int i = 0, j = n - 1;
        for (; i < a; i++) {
            ans[i] = '-';
        }
        for (;j > n - 1 - b; j--) {
            ans[j] = '-';
        }
        for (int k = 0; k < c; k++) {
            ans[i++] = '?';
        }
        for (int k = 0; k < c; k++) {
            ans[j--] = '?';
        }
        if (k == n) {
            ans = string(n, '-');
        }
        cout << ans << '\n';
    }
}