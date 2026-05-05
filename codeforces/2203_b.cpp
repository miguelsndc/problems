#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    string s; cin >> s;
    int n = (int)(s.size());
    auto soma = [&](string s) {
        int sum = 0;
        for (char c : s) {
            int v = (int)(c - '0');
            sum += v;
        }
        return sum;
        };
    /*
        menor numero de movimentos pra fazer
        soma digitos <= 9
    */
    vector<int> v;
    int k = soma(s);
    for (int i = 0; i < n; i++) {
        int r = (int)(s[i] - '0');
        if (i == 0) r--;
        v.push_back(r);
    }
    sort(v.begin(), v.end());
    if (k <= 9) {
        cout << 0 << '\n';
        return;
    }
    int op = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        k -= v[i];
        op++;
        if (k <= 9) {
            break;
        }
    }
    cout << op << '\n';

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while (tt--) slve();
}