#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    vector<int> x;
    for (int i = 0; i < n; i++) {
        int l = 0, r = x.size() - 1, ans = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            if (x[m] > a[i]) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (ans == -1) x.push_back(a[i]); 
        else x[ans] = a[i];
    }
    cout << x.size() << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}