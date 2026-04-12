#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
struct Node {
    int fail = 0, exit = 0, max = 0, depth = 0, cnt = 0;
    array<int, 26> next = {};
    vector<int> end;
};
void solve() {
    int n; cin >> n;
    vector<string> ss(n); vector<vector<int>> h(n);
    for (auto &s: ss) cin >> s;
    for (int i = 0; i < n; i++) {
        h[i].resize(sz(ss[i]));
        for (int j = 0; j < sz(h[i]); j++) cin >> h[i][j];
    }
    vector<Node> trie; trie.emplace_back();
    function<void(int)> insert = [&] (int idx) {
        int node = 0;
        for (int i = 0; i < sz(ss[idx]); i++) {
            int ch = ss[idx][i] - 'a';
            if (not trie[node].next[ch]) {
                trie[node].next[ch] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[ch];
            trie[node].cnt++;
            trie[node].depth = i + 1;
            trie[node].max = max(trie[node].max, h[idx][i]);
        }
        trie[node].end.push_back(ss[idx].size());
    };
    for (int i = 0; i < n; i++) insert(i);
    queue<int> q;
    for (int j = 0; j < 26; j++) {
        int i = trie[0].next[j];
        if (i != 0) q.push(i);
    }
    vector<int> order;
    while(not q.empty()) {
        int i = q.front(); q.pop();
        order.push_back(i);
        int f = trie[i].fail;
        if (not trie[f].end.empty()) {
            trie[i].exit = f;
        } else {
            trie[i].exit = trie[f].exit;
        }
        for (int j = 0; j < 26; j++) {
            int c = trie[i].next[j];
            if (c != 0) {
                trie[c].fail = trie[f].next[j];
                q.push(c);
            } else {
                trie[i].next[j] = trie[f].next[j];
            }
        }
    }
    for (int i = sz(order) - 1; i >= 0; i--) {
        int u = order[i];
        int f = trie[u].fail;
        if (f != 0) {
            trie[f].max = max(trie[f].max, trie[u].max);
        }
    }
    long long ans = 0;
    for (int i = 0; i < sz(trie); i++) {
        long long cur = 1ll * trie[i].cnt * trie[i].depth * trie[i].max;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();
}
