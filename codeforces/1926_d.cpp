#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto& x : a) cin >> x, mp[x]++;
    /*
        grupos de 1 cara ou 2 caras
        junta i com ~i
    */
    int groups = 0;
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 0) continue;
        int flip = 0;
        for (int b = 0; b < 31; b++) {
            if (!(a[i] & (1 << b))) flip |= (1 << b);
        }
        if (mp.count(flip) and mp[flip] > 0) {
            mp[a[i]]--;  mp[flip]--;
            groups++;
        }
    }
    for (auto& [v, f] : mp) {
        if (f > 0) groups += f;
    }
    cout << groups << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}