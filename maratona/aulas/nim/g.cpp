#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
const int mx = 2005;
vector<int> nim(mx);
void preprocess() {
    nim[0] = nim[1] = nim[2] = 0;
    for (int i = 3; i < mx; i++) {
        vector<int> reach(mx + 1);
        for (int k = i - 1; k > i / 2; k--) {
            reach[nim[k] ^ nim[i - k]] = true;
        }
        int mex = 0;
        while (mex < mx and reach[mex]) mex++;
        nim[i] = mex;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    preprocess();
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        if (n < mx) {
            cout << (nim[n] != 0 ? "first\n" : "second\n");
        } else {
            cout << "first\n";
        }
    }
}