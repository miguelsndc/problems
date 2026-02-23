#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
void file_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
};
struct Rect {
    int x1, y1, x2, y2;
};
void dale() {
    int n, k;
    cin >> n >> k;
    vector<Rect> rect(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rect[i] = {a,b,c,d};
        mx = max({mx, a, b, c, d});
    }
    const int sz = mx + 2;
    vector sweep(sz, vector<int>(sz));
    for (auto [x1, y1, x2, y2] : rect) {
        sweep[x1][y1]++;
        sweep[x2][y1]--;
        sweep[x1][y2]--;
        sweep[x2][y2]++;
    }   
    for (int i = 1; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            sweep[i][j] += sweep[i - 1][j];
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int j = 1; j < sz; j++) {
            sweep[i][j] += sweep[i][j - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < sz; i++) {
        ans += count(sweep[i].begin(), sweep[i].end(), k);
    }
    cout << ans;
}
int main() {
    file_io("paintbarn");
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}