#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

void slve() {
    int n, m, l; cin >> n >> m >> l;
    vector<int> flash(l + 1), anim(m);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        flash[x] = true;
    }
    int curr = n;
    for (int i = 1; i <= l; i++) {
        anim[min(m, curr + 1) - 1]++;
        sort(anim.rbegin(), anim.rend());
        if (curr > 0 and flash[i]) {
            anim[0] = 0;
            sort(anim.rbegin(), anim.rend());
            curr--;
        }
    }
    cout << anim[0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}