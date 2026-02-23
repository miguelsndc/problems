#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
int a[maxn], n;
void dale() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    bool is_a = true;
    ll z = 0, w = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (is_a) {
            if (a[i] % 2 == 0) z += a[i];
            is_a ^= 1;
        } else {
            if (a[i] & 1) w += a[i];
            is_a ^= 1;
        }
    }
    if (z > w) {
        cout << "Alice\n";
    } else if (z == w) {
        cout << "Tie\n";
    } else {
        cout << "Bob\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while(tt--) dale();
}