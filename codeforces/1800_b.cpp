#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

void slve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<char,int> up, low;
    for (char c: s) {
        if (c >= 'A' and c <= 'Z') up[c]++;
        if (c >= 'a' and c <= 'z') low[c]++;
    }
    int pairs = 0;
    for (int i = 0; i < 26; i++) {
        char cl = char(i + 'a');
        char cu = char(i + 'A');
        int m = min(up[cu], low[cl]);
        pairs += m;
        up[cu] -= m; low[cl] -= m;
    }
    int op = 0;
    for (int i = 0; i < 26; i++) {
        char cl = char(i + 'a');
        char cu = char(i + 'A');
        while(op < k and low[cl] >= 2) {
            low[cl] -= 2;
            pairs++;
            op++;
        }
        while(op < k and up[cu] >= 2) {
            up[cu] -= 2;
            pairs++;
            op++;
        }
    }
    cout << pairs << '\n';
}c

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}