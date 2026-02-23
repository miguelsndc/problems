#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int base = 137;
const int MAXN = 200005;

ll pow1[MAXN], pow2[MAXN];

void calc_pow() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        pow1[i] = (pow1[i - 1] * base) % mod1;
        pow2[i] = (pow2[i - 1] * base) % mod2;
    }
}

using HashT = pair<ll, ll>;

struct Hashing {
    vector<ll> pref1, pref2;
    Hashing(string& s) {
        pref1.assign(s.size() + 1, 0);
        pref2.assign(s.size() + 1, 0);
        for (int i = 0; i < s.size(); i++) {
            ll val = s[i] - 'a' + 1;
            pref1[i + 1] = ((pref1[i] * base) % mod1 + val) % mod1;
            pref2[i + 1] = ((pref2[i] * base) % mod2 + val) % mod2;
        }
    }

    HashT get(int a, int b) {
        ll h1 = (mod1 + pref1[b + 1] - (pref1[a] * pow1[b - a + 1]) % mod1) % mod1;
        ll h2 = (mod2 + pref2[b + 1] - (pref2[a] * pow2[b - a + 1]) % mod2) % mod2;
        return { h1, h2 };
    }
};

void dale() {
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> trie(n + 1, vector<int>(26, -1));
    for (int i = 1; i <= n; i++) {
        int par; char edge; cin >> par >> edge;
        trie[par][edge - 'a'] = i;
    }

    vector<pair<HashT, int>> table;
    function<void(int, HashT)> dfs = [&](int node, HashT h) -> void {
        table.push_back({ h, node });
        for (int i = 0; i < 26; i++) {
            if (trie[node][i] != -1) {
                ll nh1 = ((h.first * base) % mod1 + (i + 1)) % mod1;
                ll nh2 = ((h.second * base) % mod2 + (i + 1)) % mod2;
                dfs(trie[node][i], { nh1, nh2 });
            }
        }
        };
    dfs(0, { 0, 0 });
    sort(table.begin(), table.end());

    string s; cin >> s;
    Hashing h(s);
    vector<int> len(m);

    for (int i = 0; i < m; i++) {
        int lo = 0, hi = min((m - i), n);
        int best = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid == 0) {
                lo = 1;
                continue;
            }
            HashT cur = h.get(i, i + mid - 1);
            auto it = lower_bound(table.begin(), table.end(), make_pair(cur, -1));
            if (it != table.end() && it->first == cur) {
                best = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        len[i] = best;
    }

    const int LOG = 20;
    vector<vector<int>> up(m + 2, vector<int>(LOG, m + 1));
    for (int i = 0; i < m; i++) {
        if (i + len[i] < m) {
            up[i][0] = i + len[i] + 1;
        }
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i <= m + 1; i++) {
            int mid = up[i][k - 1];
            if (mid > m) up[i][k] = m + 1;
            else up[i][k] = up[mid][k - 1];
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int curr = l;
        int ans = 0;
        for (int k = LOG - 1; k >= 0; k--) {
            int nxt = up[curr][k];
            if (nxt <= m && nxt - 1 <= r) {
                ans += (1 << k);
                curr = nxt;
            }
        }
        int dest = 0;
        if (curr <= r) {
            HashT rem = h.get(curr, r);
            auto it = lower_bound(table.begin(), table.end(), make_pair(rem, -1));
            if (it != table.end() && it->first == rem) dest = it->second;
        }
        cout << ans << " " << dest << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    calc_pow();
    int tt; cin >> tt;
    while (tt--) dale();
}