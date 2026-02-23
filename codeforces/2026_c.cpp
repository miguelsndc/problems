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
        string s; cin >> s;
        vi a(n + 1);
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = (int)(s[i - 1] - '0');
        }
        int l = 1, r = count(all(a), 1) + 1; 
        while(r - l > 1) {
            int m = l + (r - l) / 2;
            // quero m bonecos de graça
            int ok = true, k = m;
            vi used(n + 1);
            for (int i = n; i >= 1; i--) {
                if (k > 0 and a[i]) {
                    used[i] = true;
                    k--;
                }
            }
            int cur = 0;
            for (int i = 1; i <= n; i++) {
                if (used[i]) {
                    cur--;
                    ok &= cur >= 0;
                }
                else cur++;
            }
            if (ok) {
                l = m;
            } else {
                r = m;
            }
        }
        ll cost = 0;
        for (int i = n; i >= 1; i--) {
            if (a[i] and l > 0) {
                l--;
            } else {
                cost += i;
            }
        }
        cout << cost << '\n';
    }
}