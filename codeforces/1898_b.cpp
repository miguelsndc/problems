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
        ll op = 0;
        for (int i = n - 1; i >= 1; i--) {
            ll k = (a[i - 1] + a[i] - 1) / a[i];
            a[i - 1] /= k;
            op += k - 1;
        }
        cout << op << '\n';
    }
}