#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; ll p; cin >> n >> p;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;
    ll xorv = 0;
    for (auto &pilha: a) {
        ll grundy = 0;
        if (p % 2 == 1) {
            grundy = pilha % 2;
        } else {
            ll rem = pilha % (p + 1);
            if (rem == p) {
                grundy = 2;
            } else {
                grundy = rem % 2;
            }
        }
        xorv ^= grundy;
    }
    cout << (xorv != 0 ? "GOOD\n": "BAD\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}