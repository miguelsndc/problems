#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n, k; cin >> n >> k;

    int size = 0;
    vector<int> rep(32, -1);

    auto insert = [&](int x) -> bool {
        for (int bit = 30; bit >= 0; bit--) if (x & (1 << bit)) {
            if (rep[bit] == -1) {
                rep[bit] = x;
                size++;
                return false;
            }
            x ^= rep[bit];
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bool res = insert(x);
    }
    for (int i = 0; i < 31; i++) {
        if (rep[i] == -1) continue;
        for (int j = 0; j < i; j++) {
            if (rep[j] != -1 && (rep[i] && (1 << j))) {
                rep[i] ^= rep[j];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        int cara = 0;
        for (int j = 0; j < 31; j++) if (rep[j] != -1 and i & (1 << j)) {
            cara ^= rep[j];
        }
        cout << cara << ' ';
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}