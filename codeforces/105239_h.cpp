#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n1, n2, n3; cin >> n1 >> n2 >> n3;
    int k; cin >> k;
    vector<int> a(k); for(int &i: a) cin >> i;
    int dp[n1 + 1][n2 + 1][n3 + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 0;
    for (int x = 0; x <= n1; x++) {
        for (int y = 0; y <= n2; y++) {
            for (int z = 0; z <= n3; z++) {
                for (int val: a) {
                    if (x - val >= 0) dp[x][y][z] |= !dp[x - val][y][z];
                    if (y - val >= 0) dp[x][y][z] |= !dp[x][y - val][z];
                    if (z - val >= 0) dp[x][y][z] |= !dp[x][y][z - val];
                }
            }
        }
    }
    if (dp[n1][n2][n3]) {
        cout << "Peter\n";
    } else {
        cout << "Vasya\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}