#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
ll resolve(ll n, ll t, vector<int> &v) {
    vector<ll> left, right;
    bool zero = false;
    for (int x: v) {
        if (abs(x) > t) continue;
        if (x == 0) zero = true;
        if (x < 0)
            left.push_back(-x);
        else if (x > 0)
            right.push_back(x);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    // quantos caras eu consigo pegar se eu pegar y caras na esquerda
    ll mx = 0;
    for (int i = 0; i < left.size(); i++) {
        if (left[i] > t) continue;
        mx = max(mx, ll(i + 1));
        ll back = 2 * left[i];
        if ((t - back) >= 0) {
            int p = lower_bound(right.begin(), right.end(), t - back) - right.begin();
            mx = max(mx, ll(i + 1) + (p == right.size() ? (ll)right.size() : (p + (right[p] <= (t - back)))));
        }
    }
    for (int i = 0; i < right.size(); i++) {
        if (right[i] > t) continue;
        mx = max(mx, ll(i + 1));
        ll back = 2 * right[i];
        if ((t - back) >= 0) {
            int p = lower_bound(left.begin(), left.end(), t - back) - left.begin();
            mx = max(mx, ll(i + 1) + (p == left.size() ? (ll)left.size() : (p + (left[p] <= (t - back)))));
        }
    }
    return mx + zero;
}
void dale() {
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    cout << resolve(n, t, a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}