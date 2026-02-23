#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
void dale() {
    string s; cin >> s;
    int n = s.size();
    vector<pii> swaps;
    for (int i = 0; i < n - 1; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < s[min_i]) {
                min_i = j;
            }
        }
        if (i != min_i) {
            swap(s[i], s[min_i]);
            swaps.push_back({i, min_i});
        }
    }
    reverse(swaps.begin(), swaps.end());
    for (auto &[x, y]: swaps) {
        cout << y + 1 << ' ' << x + 1 << '\n';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}