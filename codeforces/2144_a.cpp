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
        vi a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int l = 1; l <= n; l++) {
            for (int r = l + 1; r <= n; r++) {
                ll left = 0, mid = 0, right = 0;
                for (int i = 1; i <= l; i++) left += a[i];
                for (int i = l + 1; i <= r; i++) mid += a[i];
                for (int i = r + 1; i <= n; i++) right += a[i];
                left %= 3; mid %= 3, right %= 3;
                if (left == mid and mid == right) {
                    cout << l << " " << r << '\n';
                    goto done;
                } else if (left != mid and mid != right and right != left) {
                    cout << l << ' ' << r << '\n';
                    goto done;
                }
            }
        }
        cout << 0 << ' ' << 0 << '\n';
        done:
    }
}