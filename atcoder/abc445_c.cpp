#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ms = 5e5 + 10;
int A[ms], n, ans[ms], loop[ms];

void dale() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = n; i >= 1; i--) {
        if (i == A[i]) ans[i] = i, loop[i] = true;
        else if (loop[A[i]]) ans[i] = ans[A[i]], loop[i] = true;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}