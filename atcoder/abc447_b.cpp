#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    vector<int> fr(26);
    for (char c: s) fr[(int)(c - 'a')]++;
    int mx = *max_element(fr.begin(), fr.end());
    string ans;
    for (char c: s) {
        if (fr[(int)(c - 'a')] < mx) {
            ans += c;
        }
    }
    cout << ans;
}
