#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
struct Node {
    int fail = 0, exit = 0;
    array<int, 26> next = {};
    vector<int> end;
};
struct AhoCorasick {
    vector<Node> trie;
    vector<int> bfs_order;
    AhoCorasick() {
        trie.emplace_back();
    }
    void insert(string& s, int idx) {
        int node = 0;
        for (char c : s) {
            int j = c - 'a';
            if (trie[node].next[j] == 0) {
                trie[node].next[j] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[j];
        }
        trie[node].end.push_back(idx);
    }
    void resolve_links() {
        queue<int> q;
        for (int j = 0; j < 26; j++) {
            int node = trie[0].next[j];
            if (node != 0) q.push(node);
        }
        while (not q.empty()) {
            int node = q.front();
            q.pop();
            bfs_order.push_back(node);
            int fail = trie[node].fail;
            if (not trie[fail].end.empty()) {
                trie[node].exit = fail;
            } else {
                trie[node].exit = trie[fail].exit;
            }
            for (int j = 0; j < 26; j++) {
                int c = trie[node].next[j];
                if (c != 0) {
                    trie[c].fail = trie[fail].next[j];
                    q.push(c);
                } else {
                    trie[node].next[j] = trie[fail].next[j];
                }
            }
        }
    }
    void match(string& t, vector<int> &ans) {
        vector<int> vis(sz(trie));
        int node = 0;
        for (char c: t) {
            node = trie[node].next[c - 'a'];
            vis[node] = true;
        }
        for (int i = sz(bfs_order) - 1; i >= 0; i--) {
            int u = bfs_order[i];
            if (vis[u]) {
                vis[trie[u].fail] = true;
            }
        }
        for (int u = 0; u < sz(trie); u++) {
            if (vis[u]) {
                for (int m: trie[u].end) {
                    ans[m] = true;
                }
            }
        }
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n;
    cin >> n;
    AhoCorasick aut;
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        aut.insert(s, i);
    }
    aut.resolve_links();
    aut.match(s, ans);
    for (int i = 0; i < n; i++) {
        cout << (ans[i] ? "YES\n" : "NO\n");
    }
}
