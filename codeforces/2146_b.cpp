#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second
void dale() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> sets(n);
    vector<int> freq(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        sets[i].resize(l);
        for (int j = 0; j < l; j++) {
            cin >> sets[i][j];
            freq[sets[i][j]]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (freq[i] == 0) {
            cout << "NO\n";
            return;
        }
    }

    int redundant = 0;
    for (auto &s : sets) {
        bool remove = true;
        for (int x : s) {
            if (freq[x] == 1) { 
                remove = false;
                break;
            }
        }
        if (remove) redundant++;
    }

    cout << (redundant >= 2 ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; cin >> tt;
    while (tt--) dale();
}
