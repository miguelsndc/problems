#include <bits/stdc++.h>
using namespace std;

void solve() {
    string f, a;
    cin >> f >> a;
    int fh = stoi(f.substr(0, 2));
    int fm = stoi(f.substr(3, 2));

    int total_f = fh * 60 + fm;

    int ah = stoi(a.substr(0, 2));
    int am = stoi(a.substr(3, 2));
    
    int total_a = ah * 60 + am;

    int diff = total_f - total_a;

    int res_h = diff / 60;
    int res_m = diff % 60;
    printf("%02d:%02d\n", res_h, res_m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}