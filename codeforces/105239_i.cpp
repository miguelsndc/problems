#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
template <class T, class U>
inline bool chmax(T &a, const U &b) {
    return a < b ? (a = b, true) : false;
}
void dale() {
    int n, k; cin >> n >> k;
    vector<int> w(n), pai(n);
    for (int i = 0; i < n; i++) {
        cin >> pai[i] >> w[i];
        --pai[i];
    }
    vector<int> dp(n), prev(n, -1);
    dp[0] = w[0];
    auto nxt = [&] (this auto nxt, int cur, int p) {
        if (p != -1 and chmax(dp[cur], dp[p] + w[cur])) {
            prev[cur] = p;
        }
        if (pai[cur] != -1) nxt(pai[cur], cur);
    };
    for (int i = 1; i < n; i++) {
        int cur = i;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}