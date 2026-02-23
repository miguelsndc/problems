#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    sort(all(a));
    int l = 0, r = 1e9, ans = 1e9;
    while(l <= r) {
        int m = l + (r - l) / 2;
        int need = 1, pos = a[0] + m;
        for (int i = 0; i < n; i++) {
            if ((a[i] - pos) <= m) continue;
            need++;
            pos = a[i] + m;
        }
        if (need <= k) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << ans;
}