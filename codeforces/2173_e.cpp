#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int l = 1; l <= (n / 2); l++) {
        int r = n - l + 1;
        while(p[l] != l or p[r] != r) {
            int i = -1, j = n - 1;
            for (int cu = 1; cu <= n; cu++) {
                if (p[i] == l) i = cu;
                if (p[i] == r) j = cu;
            }
            int x, y;
            if (i == r or j == l) {
                x = l; y = r;
            } else if (i != l) {
                x = l, y = i; 
            } else {
                x = j;
                y = r;
            }
            cout << "? " << x << " " << y << endl;
            int u, v; cin >> u >> v;
            if (u == -1) exit(0); 
            swap(p[u], p[v]);
        } 
    }
    cout << "!" << endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}