#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string a, b; int n, last, total, reached;
void dole(int i, int pos) {
    if (i == n) {
        if (pos == last) reached++;
        total++;
        return;
    }
    if (b[i] == '+') {
        dole(i + 1, pos + 1);
    } else if (b[i] == '-') {
        dole(i + 1, pos - 1);
    } else {
        dole(i + 1, pos + 1);
        dole(i + 1, pos - 1);
    }
};
void dale() {
    cin >> a >> b;
    n = a.size();
    last = 0; 
    for (char c : a)
        if (c == '+')
            last++;
        else
            last--;
    dole(0, 0);
    cout.setf(ios::fixed);
    cout.precision(10);
    double ans = (reached + .0) / (total + .0);
    cout << ans  << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}