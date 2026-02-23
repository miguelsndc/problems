#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
void dale() {
    int l, r; cin >> l >> r;
    int n = r - l + 1;
    int pw = 1;
    while(pw < r) {
        pw = pw << 1 | 1;
    }
    set<int> s;
    for (int i = l; i <= r; i++) {
        s.insert(i);
    }
    vector<int> a(r + 1);
    ll ans = 0;
    for (int i = r; i >= l; i--) {
        while(!s.count(pw - i)) {
            pw >>= 1;
        }
        a[i] = pw - i;
        ans += i | a[i];
        s.erase(a[i]);
    }
    cout << ans << '\n';
    for (int i = 0; i < r + 1; i++) cout << a[i] << " \n"[i == r];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}