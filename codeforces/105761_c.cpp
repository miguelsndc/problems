#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    vector<int> a(5);
    for (int &x: a) cin >> x;
    sort(a.begin(), a.end());
    do {
        if (a[0] == (a[1] + a[2] + a[3]) and (a[1] * 3 + a[2]) == a[4]) {
            for (int x: a) cout << x << ' ';
            cout << '\n';
            return;
        }
    } while(next_permutation(a.begin(), a.end()));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}