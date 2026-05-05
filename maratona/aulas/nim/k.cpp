#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
/*
    preciso saber se ja fiz o movimento numa pilha
    [tam][movimento] = ja fiz ?

*/
map<pair<int,ll>, int> mp;
int grundy(int s, ll mask) {
    if (mp.count({s, mask})) return mp[{s, mask}];
    set<int> reach;
    for (int i = 1; i <= s; i++) {
        if (!(mask & (1ll << i))) {
            reach.insert(grundy(s - i, mask | (1ll << i)));
        }
    }
    int mex = 0;
    while(reach.count(mex)) mex++;
    return mp[{s, mask}] = mex;
}
void slve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<int> grundy(61);
    for (auto& x : p) cin >> x;
    /*
        i aparece i + 1 vezes;
    */
    int cur = 1;
    for (int i = 1; i <= 60 and cur < 61; i++) {
        for (int j = 0; j < i + 1 and cur < 61; j++) {
            grundy[cur++] = i;
        }
    }
    int nim = 0;
    for (int x: p) nim ^= grundy[x];   
    cout << (nim != 0 ? "NO": "YES");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}