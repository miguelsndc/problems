#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    set<int> s;
    while(n) {
        int x = n % 10;
        s.insert(x);
        n /= 10;
    }
    if (s.size() == 1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}