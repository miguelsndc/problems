    #include <bits/stdc++.h>
    using ll = long long;
    using namespace std;
    using ii = pair<int, int>;
    #define sz(x) ((int)(x.size()))
    void dale() {
        ll x;
        while((cin >> x)) {
            int cur = 196, t = 199, msb = 63 - __builtin_clzll(x);
            if (x == 0) {
                cout << "2\n1 1\n2 1\n";
                continue;
            }
            vector<ii> portais;
            for (int bit = msb - 1; bit >= 0; bit--) {
                if (x & (1ll << bit)) {
                    portais.push_back({cur + 1, t});
                    portais.push_back({cur + 2, t});
                    t = cur;
                    cur -= 3;
                    portais.push_back({cur + 1, t});
                    portais.push_back({cur + 2, 199});
                    t = cur;
                    cur -= 3;
                } else {
                    portais.push_back({cur + 1, t});
                    portais.push_back({cur + 2, t});
                    t = cur;
                    cur -= 3;
                }
            }
            portais.push_back({2, 2});
            portais.push_back({1, t});
            cout << portais.size() << '\n';
            for (auto &[a, b]: portais) {
                cout << a << ' ' << b << '\n';
            }
        }
    }
    int main() {
        cin.tie(0)->sync_with_stdio(false);
        int tt = 1; // cin >> tt;
        while(tt--) dale();
    }