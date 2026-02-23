#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void dale() {
    int vis = 0;
    for (int i = 0; i < 4; i++) {
        int x; cin >> x;
        if (x > 0) vis++;
    }
    if (vis == 0) {
        cout << "Typically Otaku\n";
    } else if (vis == 1) {
        cout << "Eye-opener\n";
    } else if (vis == 2) {
        cout << "Young Traveller\n";
    } else if (vis == 3) {
        cout << "Excellent Traveller\n";
    } else {
        cout << "Contemporary Xu Xiake\n";
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}