#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int top, bot, left, right, front, back;
    cin >> top >> bot >> left >> right >> front >> back;
    ll sides = (right * back + left * back + front * left + front * right);
    cout << top * sides + bot * sides << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}