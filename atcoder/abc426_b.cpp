#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    string s; cin >> s;
    map<char,int> mp;
    for (char c: s) mp[c]++;
    for (auto[ch, freq]: mp) {
        if (freq == 1) {
            cout << ch << '\n';
            return;
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}