#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int f(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q;
        cin >> n >> q;
        vi a(n + 1);
        set<int> s{0};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] > 9) {
                s.insert(i);
            }
        }
        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int l, r;
                cin >> l >> r;
                auto it = s.lower_bound(l);
                while (it != s.end() && *it <= r) {
                    int i = *it;
                    a[i] = f(a[i]);
                    if (a[i] <= 9) {
                        it = s.erase(it);  
                    } else {
                        ++it;
                    }
                }
            } else {
                int x;
                cin >> x;
                cout << a[x] << '\n';
            }
        }
    }
}