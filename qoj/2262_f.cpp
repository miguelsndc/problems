#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        string s; cin >> s;
        int cnt = 0;
        for (char c: s) {
            if (c == 'D') break;
            cnt++;
        }
        cout << cnt << '\n';
    }
}