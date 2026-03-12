#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    string P;
    cin >> P;
    vector<string> id(n);
    vector<int> r(n), pts(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> id[i];
        r[i] = i + 1;
    }
    int q;
    cin >> q;
    while (q--) {
        string query;
        cin >> query;
        if (query == "scoreboard") {
            vector<int> ord(n);
            iota(ord.begin(), ord.end(), 0);
            sort(ord.begin(), ord.end(),
                 [&](int i, int j) {
                    if (pts[i] == pts[j]) {
                        return r[i] < r[j];
                    }
                    return pts[i] > pts[j];
                  });
            int rank = 0, last = 1e9 + 1;
            for (int i = 0; i < n; i++) {
                if (pts[ord[i]] == 0) break;
                if (pts[ord[i]] < last) {
                    rank++;
                    last = pts[ord[i]];
                }
                cout << rank << ' ' << r[ord[i]] << ' ' << id[ord[i]]
                     << ' ' << pts[ord[i]] << '\n';
            }
        } else {
            int st_id, qtd;
            cin >> st_id >> qtd;
            string pass;
            cin >> pass;
            if (pass != P) {
                cout << "Wrong password please try again\n";
            } else {
                pts[--st_id] += qtd;
                cout << "Updated successfully\n";
            }
        }
        cout << "---\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
