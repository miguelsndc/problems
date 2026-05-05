#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (auto &x: v) cin >> x;
    set<int> s; map<int, int> fr;
    for (int i = 0; i < k; i++) {
        if (fr[v[i]]++ == 0) s.insert(v[i]);
    }
    cout << (s.size()) << ' ';
    for (int i = k; i < n; i++) {
        if (fr[v[i]]++ == 0) s.insert(v[i]);
        if (fr[v[i - k]]-- == 1) s.erase(v[i - k]);
        cout << s.size() << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while(tt--) slve();
}