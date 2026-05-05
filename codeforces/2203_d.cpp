#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int mx = n + m + 1;
    vector<int> freq(mx), in_a(mx), in_b(mx), temdivisor(mx);
    for (int x : b) freq[x]++;
    for (int x : a) in_a[x] = true;
    for (int x : b) in_b[x] = true;
    int gacnt = 0, gbcnt = 0, gccnt = 0;
    /*
        tres grupos
        a: divide todo mundo
        se x | gcd(b1,...,bn)
        b: divide alguns e n divide outros
        c: divide ngm

        o primeiro q esgotar b vence
        se b & 1 alice se nao bob
    */
    long long g = 1; bool pode = true;
    for (int x : a) {
        g = lcm(g, x);
        if (g > mx) {
            pode = false;
            break;
        }
    }

    if (pode) {
        for (int x : b) {
            if (x % g == 0) {
                gacnt++;
            }
        }
    }

    vector<int> c = a;
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    for (int x: c) {
        for (int j = x; j < mx; j += x) {
            if (in_b[j]) {
                temdivisor[j] = true;
            }
        }
    }

    // for (int i = mx - 1; i >= 1; i--) {
    //     if (in_b[i]) {
    //         bool bom = true;
    //         for (int j = i; j >= 1; j -= i) {
    //             if (in_a[j]) bom = false;
    //         }
    //         if (bom) {
    //             gbcnt += freq[i];
    //         }
    //     }
    // }
    for (int i = 1; i < mx; i++) {
        if (!temdivisor[i]) gbcnt += freq[i];
    }
    gccnt = m - (gbcnt + gacnt);

    /*

    */
    // cout << "divide todos: " << gacnt << '\n';
    // cout << "divide ninguem: " << gbcnt << '\n';
    // cout << "divide alguns: " << gccnt << '\n';
    if (gacnt + (gccnt % 2) > gbcnt) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}