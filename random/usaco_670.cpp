#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define x first
#define y second
int main(){
    // freopen("checklist.in", "r", stdin);
    // freopen("checklist.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pii> h(n), g(m);
    for (int i = 0; i < n; i++) cin >> h[i].x >> h[i].y;
    for (int i = 0; i < m; i++) cin >> g[i].x >> g[i].y;
}
