
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
        ll n, k; cin >> n >> k;
        vi v;
        while(n) {
            v.push_back((n + 1)/ 2);
            n /= 2;
        }
        int tot = 0, pw = 1;
        for (int x: v) {
            if (tot < k and k <= tot + x) {
                cout << pw * (2 * (k - tot) - 1) << '\n';
                goto done;
            }
            tot += x;
            pw *= 2;
        }
        done:
    }
}