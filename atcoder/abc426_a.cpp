#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    string x, y; cin >> x >> y;
    if (x == y) {
        cout << "Yes\n";
    } else if ((x == "Serval" and y == "Ocelot") or (x == "Lynx" and (y == "Serval" or y == "Ocelot"))) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}
