#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    /*
    tem uma janela de tamanho pelo menos m com todo mundo igual ? entao nao
    */
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int r = 0, ans = 0;
    for (int l = 0; l < n; l++) {
        while(r + 1 < n and a[l] == a[r + 1]) r++;
        ans = max(ans, r - l + 1);
    }
    if (ans >= m) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}