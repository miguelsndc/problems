#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    while(n--) {
        string a, b; cin >> a >> b;
        while(a.back() == '0') a.pop_back();
        while(b.back() == '0') b.pop_back();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        ll x = stoll(a);
        ll y = stoll(b);
        ll z = x + y;
        string sz = to_string(z);
        while(sz.back() == '0') sz.pop_back();
        reverse(sz.begin(), sz.end());
        cout << sz << '\n';
    }
}