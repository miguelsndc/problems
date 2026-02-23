#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int LIM = 200000 + 5;
vector<int> spf(LIM);
void sieve() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i < LIM; i++) if (spf[i] == i)
        for (int j = i * i; j < LIM; j += i)
            if (spf[j] == j) spf[j] = i;
}

vector<int> fatora(int x) {
    vector<int> res;
    while (x > 1) {
        int p = spf[x];
        res.push_back(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

void dale() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b(n); for (auto &x : b) cin >> x;
    vector<int> freq(LIM);
    for (int x : a) {
        for (int p : fatora(x)) {
            if (++freq[p] >= 2) {
                cout << 0 << "\n";
                return;
            }
        }
    }
    for (int x : a) {
        for (int p : fatora(x + 1)) {
            if (freq[p]) {
                cout << 1 << "\n";
                return;
            }
        }
    }

    cout << 2 << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    sieve();
    int tt = 1; cin >> tt;
    while(tt--) dale();
}
