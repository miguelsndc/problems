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
        vector bits(n, vi(20));
        set<int> s;
        for (int &i: a) { cin >> i; s.insert(i); }
        int mx = -1;
        for (int b = 0; b < 20; b++) {
            int last = -1, mx_dist = -1, any = false;;
            for (int i = 0; i < n; i++) {
                if (a[i] & (1 << b)) {
                    mx_dist = max(mx_dist, abs(last - i));
                    any = true;
                    last = i;
                }
            }
            if (any) {
                mx_dist = max(mx_dist, n - last);
            }
            mx = max(mx, mx_dist);
        }
        if (n == 1 or s.size() == 1) {
            cout << 1 << '\n';
        } else if(mx == -1) {
            cout << n << '\n';
        } else {
            cout << mx << '\n';
        }
    }
}