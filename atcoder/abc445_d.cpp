#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void dale() {
    int h, w, n; cin >> h >> w >> n;
    int curh = h, curw = w, r = 1, c = 1;
    vector<pair<int, int>> ans(n), caras(n); int cnt = 0;
    map<int, set<int>> mph, mpw;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        caras[i] = { a, b };
        mph[a].insert(i);
        mpw[b].insert(i);
    }
    while (cnt < n) {
        while (mph[curh].size()) {
            int i = *mph[curh].begin();
            auto [th, tw] = caras[i];
            ans[i] = { r, c };
            curw -= tw;
            r += tw;
            mpw[tw].erase(i);
            mph[curh].erase(i);
            cnt++;
        }
        while (mpw[curw].size()) {
            int i = *mpw[curw].begin();
            auto [th, tw] = caras[i];
            ans[i] = { r, c };
            curh -= th;
            c += th;
            mpw[tw].erase(i);
            mph[th].erase(i);
            cnt++;
        }
    }
    for (auto &[x, y]: ans) {
        cout << y << ' ' << x << '\n';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--) dale();
}