#include <bits/stdc++.h>
using ll = long long;
#define sz(x) ((int)(x.size()))
using namespace std;
void dale() {
    string s;
        getline(cin, s);
        vector<int> a;
        int tam = 1;
        for (char c : s) {
            if (c == ' ') {
                a.push_back(tam);
                tam = 1;
            }
            else {
                tam++;
            }
        }
        a.push_back(tam);
        vector<ll> ps(sz(a) + 1);
        set<int> tem;
        for (int i = 0; i < sz(a); i++) {
            ps[i + 1] = ps[i] + a[i];
            tem.insert(ps[i + 1]);
        }
        vector<int> div;
        ll tot = s.size() + 1;
        for (ll i = 1; i * i <= tot; i++) {
            if (tot % i == 0) {
                div.push_back(i);
                if (tot / i != i) div.push_back(tot / i);
            }
        }
        sort(div.begin(), div.end());
        for (int d : div) {
            if (d >= tot) continue;
            bool ok = true;
            for (int j = d; j <= tot and ok; j += d) {
                ok &= tem.count(j);
            }
            if (ok) {
                cout << "YES\n"; return;
            }
        }
        cout << "NO\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    cin.ignore();
    while (tt--) {
        dale();
    }
}