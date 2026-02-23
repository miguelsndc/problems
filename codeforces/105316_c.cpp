#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n, D; cin >> n >> D;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0];
    for (int i = 0; i < n; i++) cin >> a[i][1];
    sort(a.begin(), a.end());
    priority_queue<int> pq;
    ll cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        pq.push(a[i][1]);
        cur += a[i][1];
        ll custa = a[i][0] + cur;
        while(pq.size() > 0 and custa > D) {
            cur -= pq.top();
            pq.pop();
            custa = a[i][0] + cur;
        }
        if (cur <= D) {
            ans = max(ans,(ll) pq.size());
        }
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}