#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    set<int> st;
    vector<int> freq(26);
    for (int i = 0; i < n; i++) a[i] = (int)(s[i] - 'a'), st.insert(a[i]), freq[a[i]]++;
    int ans = n;
    vector<int> pref_ev(n + 1), pref_od(n + 1), suf_ev(n + 1), suf_od(n + 1);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int x = 0; x < n; x++) {
                pref_ev[x + 1] = pref_ev[x] + (x % 2 == 0 ? a[x] == i : a[x] == j);
                pref_od[x + 1] = pref_od[x] + (x % 2 == 0 ? a[x] == j : a[x] == i);
            }
            for (int x = n - 1; x >= 0; x--) {
                suf_ev[x] = suf_ev[x + 1] + (x % 2 == 0 ? a[x] == i : a[x] == j);
                suf_od[x] = suf_od[x + 1] + (x % 2 == 0 ? a[x] == j : a[x] == i);
            }
            if (n % 2 == 0) {
                ans = min(ans, n - pref_ev[n]);
                continue;
            }
            for (int x = 0; x < n; x++) {
                int eq = pref_ev[x] + suf_od[x + 1];
                ans = min(ans, (n ) - eq);
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}