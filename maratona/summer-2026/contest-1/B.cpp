#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
const int inf = 1e9 + 10;
void dale() {
    int n; cin >> n;
    string s; cin >> s;
    int m; cin >> m;

    struct node {
        int minsum = inf, ps = 0;
    };

    vector<node> tree(8 * n);

    auto join = [&] (node &left, node &right) {
        node nxt;
        nxt.ps = left.ps + right.ps;
        nxt.minsum = min({left.minsum, nxt.ps, left.ps + right.minsum});
        return nxt;
    };
    auto update = [&] (auto &&f, int pos, int val, int l, int r, int v = 0) -> void {
        if (l == r) {
            tree[v].ps = val;
            tree[v].minsum = val;
        } else {
            int mid = (l + r) / 2;
            if (pos <= mid) {
                f(f, pos, val, l, mid, v * 2 + 1);
            } else {
                f(f, pos, val, mid + 1, r, v * 2 + 2);
            }
            tree[v] = join(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    };

    for (int i = 0; i < n; i++) update(update, i, (s[i] == '(' ? 1: -1), 0, n - 1);

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        if (k == 0) {
            cout << ((tree[0].minsum >= 0 and tree[0].ps == 0) ? "YES\n" : "NO\n");
        } else {
            if (s[k - 1] == '(') update(update, k - 1, -1, 0, n - 1);
            else update(update, k - 1, 1, 0, n - 1);
            s[k - 1] = (s[k - 1] == '(') ? ')' : '(';
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    for (int i = 1; i <= 10; i++) {
        cout << "Test " << i << ":\n";
        dale(); 
    }
}