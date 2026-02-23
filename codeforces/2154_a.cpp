#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
void dale() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> prot(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int contains = 0;
            for (int j = max(0, i - k + 1); j < i; j++) {
                if (s[j] == '1') contains = true;
            }
            if (!contains and !prot[i]) {
                prot[i] = true;
            }
        }
    }
    cout << accumulate(prot.begin(), prot.end(), 0) << "\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}