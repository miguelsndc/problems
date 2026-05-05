#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define yes cout << "YES\n";
#define no cout << "NO\n";
void slve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    int maiorpar = -1e9, menorpar = 1e9, maiorimpar = -1e9, menorimpar = 1e9,
        tempar = false, temimpar = false;
    /*
        se maior par > maior impar e menor impar > menor par n tem como pq tao "cercados"
        msma coisa pra outro % 2
        se for mesma paridade tem q estar sortado
    */
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            maiorpar = max(maiorpar, a[i]);
            menorpar = min(menorpar, a[i]);
            tempar = true;
        }
        else {
            maiorimpar = max(maiorimpar, a[i]);
            menorimpar = min(menorimpar, a[i]);
            temimpar = true;
        }
    }
    if (is_sorted(a.begin(), a.end())) {
        yes
            return;
    }
    if (!tempar or !temimpar) {
        bool sortado = is_sorted(a.begin(), a.end());
        cout << (sortado ? "YES\n" : "NO\n");
        return;
    }
    int mparvisto = -1e9, mimparvisto = -1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (a[i] < mparvisto and mparvisto > maiorimpar and a[i] < menorimpar) {
                no
                    return;
            }
            mparvisto = max(mparvisto, a[i]);
        }
        else {
            if (a[i] < mimparvisto and mimparvisto > maiorpar and a[i] < menorpar) {
                no
                    return;
            }
            mimparvisto = max(mimparvisto, a[i]);
        }
    }
    yes
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}