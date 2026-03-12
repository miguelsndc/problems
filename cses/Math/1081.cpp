#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (auto &i: a) cin >> i;
    int mx = *max_element(a.begin(), a.end());
    vector<int> freq(mx + 1);
    for (auto i: a) freq[i]++;

    for (int i = mx; i >= 1; i--) {
        int f = 0;
        for (int j = i; j <= mx; j += i) {
            f += freq[j];
        }
        if (f > 1) {
            cout << i << '\n';
            break;
        }
    }
}
