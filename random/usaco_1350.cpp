#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vi a(n), q(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> q[i];
        p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int v1, int v2) {
        return make_pair(a[p[v1]], q[p[v1]]) < make_pair(a[p[v2]], a[p[v2]]);
    });
}