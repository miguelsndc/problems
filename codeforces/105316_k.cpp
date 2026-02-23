#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> s(8);
        for (int &i: s) cin >> i;
        cout << accumulate(s.begin(), s.end(), 0) << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}