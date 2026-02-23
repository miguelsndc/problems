#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    string s; cin >> s;
    int n = sz(s);
    vector<int> nb(n);
    auto nxt = [&](int i, char c) -> int {
        for(; i; i = nb[i - 1]) if (s[i] == c) return i + 1;
        return s[0] == c;
    };
    for (int k = 1; k < n; k++) {
        nb[k] = nxt(nb[k - 1], s[k]);
    }
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) cnt[nb[i]]++;
    for (int i = n; i > 0; i--) cnt[nb[i - 1]] += cnt[i];
    for (int i = 1; i <= n; i++) cnt[i]++;
    vector<pii> ans;
    int len = n;
    assert(nb[0] == 0);
    while(len > 0) {
        ans.push_back({len, cnt[len]});
        len = nb[len - 1];
    }
    rg::reverse(ans);
    cout << ans.size() << '\n';
    for (auto[x, y]: ans) cout << x << ' ' << y <<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}