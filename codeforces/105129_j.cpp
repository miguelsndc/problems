#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    i64 x, d;
    cin >> x >> d;
    i64 original = x;
    string s = to_string(x);
    while (true) {
        s = to_string(x);
        int pos = -1;
        for (int i = 0; i < s.size(); i++) {
            if ((int)s[i] - '0' == d) {
                pos = i;
                break;
            }
        }
        if (pos == -1) break; 
        i64 p = 1;
        for (int i = 0; i < (int)s.size() - 1 - pos; i++) p *= 10;
        x = (x / p + 1) * p;
    }
    
    cout << x - original << endl;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
