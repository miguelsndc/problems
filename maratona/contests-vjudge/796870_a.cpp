#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    auto palindromo = [&] (int l, int r) {
        int i = l, j = r;
        while(i < j) {
            if (s[i] == s[j]) {
                i++, j--;
            } else {
                return false;
            }
        }
        return true;
    };
    bool ok = true;
    int n = (int)(s.size());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (palindromo(i, j)) {
                ok &= (j - i + 1) & 1;
            }
        }
    }
    cout << (ok ? "Odd." : "Or not.");
}