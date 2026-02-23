#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    vector<int> freq(n * n);
    ll ans = 0;
    for (int j = n - 1; j >= 0; j--) {
        int k = j + 1;
        for (int l = k + 1; l < n; l++) {
            freq[a[k] * n + a[l]]++;
        }
        for (int i = 0; i < j; i++) {
            ans += freq[a[i] * n + a[j]];
        }
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}