#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--) {
        int n, k; cin >> n >> k;
        vector<string> s(n);
        for (auto &x: s) cin >> x;
        vector<int> a;
        for (auto x: s) {
            string cur = "";
            vector<int> v;
            for (char c: x) {
                if (c == '/') cur.clear();
                else cur += c;
            }
            a.push_back(stoi(cur));
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < k; i++) {
            cout << a[i] << " \n"[i == k - 1];
        }
    }
}