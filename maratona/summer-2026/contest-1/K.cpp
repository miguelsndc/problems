#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n;
    cin >> n;
    vector<int> a(n), d(n), ans(n), L(n, -1), R(n, -1), morto(n, false);
    for (int& i : a) cin >> i;
    for (int& i : d) cin >> i;
    set<int> s, morreu;
    for (int i = 1; i < n; i++) L[i] = i - 1;
    for (int i = 0; i + 1 < n; i++) R[i] = i + 1;
    for (int i = 0; i < n; i++) {
        int dano = 0;
        if (L[i] != -1) dano += a[L[i]];
        if (R[i] != -1) dano += a[R[i]];
        if (dano > d[i]) {
            morto[i] = true;
            ans[0]++;
            morreu.insert(i);
        }
    }

    for (int x : morreu) {
        morto[x] = true;
        if (R[x] != -1) {
            L[R[x]] = L[x];
            if (L[R[x]] != -1) s.insert(L[R[x]]);
        }
        if (L[x] != -1) {
            R[L[x]] = R[x];
            if (R[L[x]] != -1) s.insert(R[L[x]]);
        }
    }

    int rnd = 1;
    while (!s.empty()) {
        morreu.clear();
        for (auto i : s) {
            if (morto[i]) continue;
            int dano = 0;
            if (L[i] != -1) dano += a[L[i]];
            if (R[i] != -1) dano += a[R[i]];
            if (dano > d[i]) {
                ans[rnd]++;
                morreu.insert(i);
            }
        }
        s.clear();
        for (int x : morreu) {
            morto[x] = true;
            if (R[x] != -1) {
                L[R[x]] = L[x];
                if (L[R[x]] != -1) s.insert(L[R[x]]);
            }
            if (L[x] != -1) {
                R[L[x]] = R[x];
                if (R[L[x]] != -1) s.insert(R[L[x]]);
            }
        }

        rnd++;
    }

    for (int x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}