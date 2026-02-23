#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
struct Node {
    int prev; string add;
};
void dale() {
    int n, q;
    cin >> n >> q;
    vector<Node> nos;
    nos.push_back({-1, ""});
    int server = 0;
    vector<int> pc(n + 1, 0);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int p ; cin >> p;
            pc[p] = server;
        } else if (t == 2) {
            int p; string s; cin >> p; cin >> s;
            nos.push_back({pc[p], s});
            pc[p] = sz(nos) - 1;
        } else {
            int p; cin >> p;
            server = pc[p];
        }
    }
    vector<string> ans;
    int cur = server;
    while(cur != -1) {
        ans.push_back(nos[cur].add);
        cur = nos[cur].prev;
    }
    rg::reverse(ans);
    for (string &s: ans) cout << s;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}