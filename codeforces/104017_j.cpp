#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> divisores(int n) {
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (n / i != i) res.push_back(n / i);
        }
    }
    return res;
}

void solve() {
    int w, l; cin >> w >> l;
    vector<int> s;
    for (int i: divisores(w)) s.push_back(i);
    for (int i: divisores(l)) s.push_back(i);
    for (int i: divisores(w - 1)) s.push_back(i);
    for (int i: divisores(l - 1)) s.push_back(i);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    set<int> ans;
    for (int x: s) {
        // ultima linha
        int cur = w;
        int sobra = w % x;
        if (sobra > 1) continue;
        // ultima coluna
        cur = l - !sobra;
        sobra = cur % x;
        if (sobra > 1) continue;
        // primeira linha
        cur = w - !sobra;
        sobra = cur % x;
        if (sobra > 1) continue;
        // primeira coluna
        cur = l - !sobra - 1;
        sobra = cur % x;
        if (sobra > 0) continue;
        ans.insert(x);
    };
    for (int x: s) {
        // ultima linha
        int cur = l;
        int sobra = l % x;
        if (sobra > 1) continue;
        // ultima coluna
        cur = w - !sobra;
        sobra = cur % x;
        if (sobra > 1) continue;
        // primeira linha
        cur = l - !sobra;
        sobra = cur % x;
        if (sobra > 1) continue;
        // primeira coluna
        cur = w - !sobra - 1;
        sobra = cur % x;
        if (sobra > 0) continue;
        ans.insert(x);
    };
    cout << ans.size() << ' ';
    for (int x: ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) solve();
}
