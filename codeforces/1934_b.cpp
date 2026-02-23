#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n; cin >> n;
    int ans = n;
    vector<int> coins = {15, 10, 6, 3, 1};
    for (int a = 0; a <= 2; a++) {
        for (int b = 0; b <= 1; b++) {
            for (int c = 0; c <= 4; c++) {
                for (int d = 0; d <= 2; d++) {
                    int val = 1 * a + 3 * b + 6 * c + 10 * d;
                    if (val <= n and (n - val) % 15 == 0) {
                        ans = min(ans, a +b+c+d +(n-val)/15);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}