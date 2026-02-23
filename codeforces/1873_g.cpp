#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void dale() {
    string s; cin >> s;
    bool tudo = s[0] == 'B' or s.back() == 'B';
    for (int i = 0; i + 1 < sz(s); i++) tudo |= (s[i] == 'B' and s[i + 1] == 'B');
    vi lens; int cur = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'A') cur++;
        else {
            if (cur != 0) lens.push_back(cur);
            cur = 0;
        }
    }
    if (cur > 0) lens.push_back(cur);
    if (sz(lens) == 0) {
        cout << 0 << '\n';
        return;
    }
    sort(all(lens));
    int ans = 0;
    for (int i = (tudo ^ 1); i < sz(lens); i++) {
        ans += lens[i];
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}