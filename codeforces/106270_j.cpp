#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        string s; cin >> s;
        int len = 0, open = 0;
        for (char c : s) {
            if (c == '\\') {
                if (open) len++, open = false;
                else open = true;
            } else {
                if (open) { open = false; break; }
                else len++;
            }
        }
        if (open) {
            cout << "INVALID\n";
        } else {
            cout << len << '\n';
        }
    }
}
