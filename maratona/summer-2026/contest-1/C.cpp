#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    struct estado {
        ll sum_w = 0, maxh = 0, k = 0;
    };
    string s;
    cin >> s;
    vector<estado> st;
    ll ans = 0;
    for (char c : s) {
        if (c == '(') {
            st.push_back({0, 0, 0});
            continue;
        }

        auto atual = st.back();
        st.pop_back();

        ll w, h;
        if (atual.k == 0) {
            w = h = 1;
        } else {
            // qtd de filhos + pontas
            w = atual.sum_w + (atual.k - 1) + 2;
            // expande p cima
            h = atual.maxh + 1;
        }

        int prof = st.size() + 1;
        ll area = h * w;
        if (prof & 1)
            ans += area;
        else
            ans -= area;

        if (!st.empty()) {
            st.back().sum_w += w;
            st.back().maxh = max(st.back().maxh, h);
            st.back().k++;
        }
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  cin >> tt;
    while (tt--) dale();
}
