#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int consec = 0, last = 0, ans = 0 ;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            consec++;
            last = i;
        } else {
            consec = 0;
        }
        if (consec == m) {
            ans++;
            int j = last;
            for (; j < min(n, i + k); j++) {
                s[i] = '1';
            }
            i = j - 1;
            consec = 0;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}