#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
void dale() {
    int n; cin >> n;
    int freq[n + 1] = {0};
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    int ans = 0;
    for (int f = 1; f <= n; f++) {
        int got = 0;
        for (int i = 1; i <= n; i++) {
            if (freq[i] >= f) {
                got += f;
            }
        }
        ans = max(ans, got);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}