#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int a, b, c; 
    while((cin >> a >> b >> c) and (a != 0 or b != 0 or c != 0)) {
        if (a == b and b == c) {
            cout << "GP " << c << '\n';
        } else if ((b - a) == (c - b)) {
            cout << "AP " << c + (c - b) << '\n';
        } else {
            cout << "GP " << c * (b / a) << '\n';
        }
        cout.flush();
    }
}