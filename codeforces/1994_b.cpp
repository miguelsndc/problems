#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s[0] == '1') {
        cout << "Yes\n";
        return;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' and t[i] == '1' and cnt1 == 0) {
            cout << "No\n";
            return;
        }
        cnt1 += (s[i] == '1');
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}