#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
int moves[] = {1, 2, 3};
void slve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto & x: p) cin >> x, x %= (4);
    vector<int> grundy(4);
    for (int i = 1; i <= 3; i++) { // valor de cada pilha
        vector<int> reach(5);
        for (int m = 0; m < 3; m++) {
            int move = moves[m];
            if (move <= i) {
                reach[grundy[i - move]] = true;
            }
        }
        int mex = 0;
        while(mex < 5 and reach[mex]) mex++;
        grundy[i] = mex;
    }
    int ans = 0;
    for (int pile: p) ans ^= grundy[pile];
    cout << (ans != 0 ? "first\n" : "second\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}