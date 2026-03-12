#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> coprimos;
    int n;
    cin >> n;
    set<int> ans;
    int prod = 1;
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) {
            coprimos.push_back(i);
            prod = ((ll)prod * i) % n;
            ans.insert(i);
        }
    }
    if (prod != 1) ans.erase(prod);
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
}
