#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vi a(n);
        for (int &i: a) cin >> i;
        int l = 0, r = n, ans = n;
        while(l <= r) {
            int m = (l + r) / 2;
            deque<int> b;
            vi mark(n + 1);
            int i = 1, j = n;
            while(i <= j and i <= m) {
                mark[i++] = mark[j--] = true;
            }
            for (int i = 0; i < n; i++) {
                if (!mark[a[i]]) b.push_back(a[i]);
            }
            for (int i = m; i >= 1; i--) {
                b.push_front(min(i, n - i + 1));
                b.push_back(max(i, n - i + 1));
            }
            if (is_sorted(all(b))) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        cout << ans << '\n';
    }
}