#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vi a(n);
        multiset<int> ms;
        for (int &i : a) cin >> i;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            ms.insert(x);
        }
        sort(all(a));
        ll ans = 0, in;
        int i = 0, j = n - 1;
        while (i <= j) {
            int x = *ms.rbegin();
            int y = *ms.begin();

            int p = abs(a[i] - x);
            int q = abs(a[i] - y);
            int r = abs(a[j] - x);
            int s = abs(a[j] - y);

            if (max(r, s) > max(p, q)) {
                ans += max(s, r);
                if (r > s) {
                    ms.erase(ms.find(x));
                } else {
                    ms.erase(ms.find(y));
                }
                j--;
            } else {
                ans += max(p, q);
                if (p > q) {
                    ms.erase(ms.find(x));
                } else {
                    ms.erase(ms.find(y));
                }
                i++;
            }
        }
        cout << ans << '\n';
    }
}