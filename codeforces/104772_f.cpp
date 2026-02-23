#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    vector suf_a(n + 1, vector<int> (n + 1)), suf_b(n + 1, vector<int>(n + 1));
    for (int i = n - 1; i >= 0; i--) {
        suf_a[i] = suf_a[i + 1];
        suf_a[i][a[i]]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        suf_b[i] = suf_b[i + 1];
        suf_b[i][b[i]]++;
    }
    vector<int> stk, fr(n + 1);
    string ans = "";
    vector dp(n, vector<int>(n, -1));
    auto dfs = [&] (auto&&self, int ptr_a, int ptr_b) -> int {
        if (ptr_a == n and ptr_b == n and stk.empty()) return true;

        for (int t = 1; t <= n; t++) {
            int tenho = suf_a[ptr_a ][t] + fr[t];
            int preciso = suf_b[ptr_b ][t];
            if (preciso > tenho) return false;
        }

        if (ptr_b < n and stk.size() > 0 and stk.back() == b[ptr_b]) {
            int x = stk.back();
            ans += 'C';
            stk.pop_back();
            fr[x]--;
            if (self(self, ptr_a, ptr_b + 1)) return true;
            ans.pop_back();
            stk.push_back(x);
            fr[x]++;
        }

        if (ptr_a < n) {
            ans += 'S';
            stk.push_back(a[ptr_a]);
            fr[a[ptr_a]]++;
            if (self(self, ptr_a + 1, ptr_b)) return true;
            ans.pop_back();
            fr[a[ptr_a]]--;
            stk.pop_back();
        }
        
        return false;
    };

    if (dfs(dfs, 0 , 0)) {
        cout << "YES\n";
        cout << ans;
    } else {
        cout << "NO\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}