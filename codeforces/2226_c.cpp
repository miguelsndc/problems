#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    int l = 0, r = n + 5, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2, ptr = 0;
        vector<int> v(mid), sob, falt;
        for (int x : a) {
            if (x < mid and !v[x]) v[x] = 1;
            else (x > 0 ? sob.push_back((x - 1) / 2) : void());
        }
        for (int i = 0; i < mid; i++) if (!v[i]) falt.push_back(i);
        for (int x : sob) if (ptr < falt.size() and x >= falt[ptr]) ptr++;
        if (ptr == falt.size()) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}