#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    ll cnt = 0;
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        if (a == (n + k - 1) / k) cnt++;
        if (a > (n + k - 1) / k) cnt = (1 << 30);
    }
    cout << (cnt <= (n - 1) % k + 1 ? "YES\n" : "NO\n");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) solve();
}