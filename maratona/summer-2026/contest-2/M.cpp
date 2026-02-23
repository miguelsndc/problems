#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n, k;
    cin >> n >> k;
    if (k >= (n - 1))
        cout << 1 << "\n";
    else
        cout << n << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}