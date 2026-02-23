#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int k; cin >> k;
    for (int L = 2; L < k; L++) {
        if (k % (L + 1) == 0) {
            cout << L <<'\n';
            return;
        }
    }
    cout << 0 << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}