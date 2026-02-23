#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template <class T, class U>
inline bool chmin(T &a, const U &b) {
    return a > b ? (a = b, true) : false;
}
void dale() {
    vector<int> mapping(256);
    mapping['i'] = mapping['j'] = '1';
    mapping['a'] = mapping['b'] = mapping['c'] = '2';
    mapping['d'] = mapping['e'] = mapping['f'] = '3';
    mapping['g'] = mapping['h'] = '4';
    mapping['k'] = mapping['l'] = '5';
    mapping['m'] = mapping['n'] = '6';
    mapping['p'] = mapping['r'] = mapping['s'] = '7';
    mapping['t'] = mapping['u'] = mapping['v'] = '8';
    mapping['w'] = mapping['x'] = mapping['y'] = '9';
    mapping['o'] = mapping['q'] = mapping['z'] = '0';

    string n;
    const int inf = 1e9 + 1;
    while ((cin >> n) and n != "-1") {
        int q;
        cin >> q;
        vector<string> words(q), mapped(q);
        for (string &s : words) cin >> s;
        for (int i = 0; i < q; i++) {
            mapped[i] = words[i];
            for (char &c : mapped[i]) c = mapping[c];
        }
        vector<int> dp(n.size() + 1, inf);
        vector<int> pai(n.size() + 1, -1);
        vector<int> qual(n.size() + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < n.size(); i++) {
            if (dp[i] == inf) continue;
            for (int w = 0; w < mapped.size(); w++) {
                int len = mapped[w].size();
                if (i + len <= n.size() && n.compare(i, len, mapped[w]) == 0) {
                    if (chmin(dp[i + len], dp[i] + 1)) {
                        pai[i + len] = i;
                        qual[i + len] = w;
                    }
                }
            }
        }
        if (dp[n.size()] == inf) {
            cout << "No solution.\n";
        } else {
            vector<string> ans;
            for (int cur = n.size(); cur > 0; cur = pai[cur]) {
                ans.push_back(words[qual[cur]]);
            }
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " \n"[i == ans.size() - 1];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}