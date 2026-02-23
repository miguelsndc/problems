#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n, m, k; cin >> n >> m >> k;
    int v = n < (m + 1) * k ? k : n / (m + 1); 
    for (int i = 0; i < n; i++) cout << i % v << " \n"[i == n - 1];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while(tt--) dale();
}