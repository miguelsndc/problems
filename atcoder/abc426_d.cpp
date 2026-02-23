#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    vector<int> mx(2), cnt(2);
    int n; cin >> n;
    string s; cin >> s;
    for (int l = 0; l < n;) {
        int r = l + 1;
        while(r < n and s[l] == s[r]) ++r;
        int len = r - l;
        int letra = s[l] - '0';
        cnt[letra] += len;
        mx[letra] = max(mx[letra], len);
        l = r;
    }
    int ans = 2 * n;
    for (int i = 0; i < 2; i++) {
        int res = 2 * (cnt[i] - mx[i]) + cnt[i ^ 1];
        ans = min(ans, res);
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}