#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    vector<int> p(n + 1), fixed;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == i) {
            fixed.push_back(i);
        }
    }
    vector<pii> swaps;
    while (fixed.size() >= 2) {
        int i = fixed.back();
        int j = fixed[fixed.size() - 2];
        swaps.emplace_back(i, j);
        swap(p[i], p[j]);
        fixed.pop_back();
        fixed.pop_back();
    }
    // sobra 1 ponto fixo no max
    if (fixed.size()) {
        int f = fixed.back();
        int cara = (f == 1 ? n : 1);
        swaps.emplace_back(cara, f);
    }
    cout << swaps.size() << '\n';
    for (auto& [a, b] : swaps) cout << a << ' ' << b << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}