#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void dale() {
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    vi found(k, false);
    int cnt = 0;
    string ans;
    for (char c: s) {
        if (ans.size() == n) break;
        cnt += !found[int(c - 'a')];
        found[int(c - 'a')] = 1;
        if (cnt == k) {
            fill(all(found), false);
            cnt = 0;
            ans += c;
        }
    }
    if (ans.size() == n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        for (int i = 0; i < k; i++) {
            if (!found[i]) {
                while(ans.size() < n) ans += char(i + 'a');
            }
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}