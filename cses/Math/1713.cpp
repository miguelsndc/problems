#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 1e6 + 10;
int cnt[mxn];
void crivo() {
    fill(cnt, cnt + mxn, 1);
    for (int i = 1; i < mxn; i++)
        for (int j = 2 * i; j < mxn; j += i) cnt[j]++;
}
int main() {
    crivo();
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cout << cnt[x] << '\n';
    }
}