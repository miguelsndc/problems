#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void dale() {
    int n; cin >> n;
    vi a(n);
    for (int &i: a) cin >> i;
    int l = 0, r = 1e9 + 9;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] < a[i + 1]) {
            r = min(r, (a[i] + a[i + 1]) / 2);
        } else if (a[i] > a[i + 1]) {
            l = max(l, (a[i] + a[i + 1] + 1) / 2);
        }
    }
    if (l <= r) {
        cout << l << '\n';
    } else {
        cout << -1 << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}