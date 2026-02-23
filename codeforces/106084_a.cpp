#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int x, d; cin >> x >> d;
    if (2 * x > d) {
        cout << "take it\n";
    } else {
        cout << "double it\n";
    }
}