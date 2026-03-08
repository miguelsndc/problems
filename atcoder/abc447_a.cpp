#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    if ((n + 1)/2 >= m) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
