#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    int r = 0; long long ans = 0;
    map<int,int> last;
    for (int l = 0; l < n; l++) {
        while(r < n and (!last.count(a[r]) or last[a[r]] < l)) {
            last[a[r]] = r;
            r++;
        }
        ans += r - l;
    }
    cout << ans;
}