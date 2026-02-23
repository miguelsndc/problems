#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/*
b + c > a
c <= b <= a
*/
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        int l = i + 2;
        for (int j = i + 1; j < n - 1; j++) {
            l = max(l, j + 1);
            while(l < n and a[i] + a[j] > a[l]) l++;
            ans += (l - j - 1);
        }
    }
    cout << ans << '\n';
}