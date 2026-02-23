#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n, res = n;
    while(l <= r) {
        int m = (l + r) / 2;
        vector<int> left;
        int s1 = 0;
        for (int i = l; i <= m; i++) {
            s1 += a[i];
            left.push_back(i);
        }
        cout << "? " << left.size() << ' ';
        for (int x: left) cout << x << ' ';
        cout << '\n';
        cout.flush();
        int ans; cin >> ans;
        if (ans > s1) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << "! " << res << '\n';
    cout.flush();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}
