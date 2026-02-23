#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
const int LIM = 200000 + 5;
vector<vector<int>> fatora(LIM);
void sieve() {
    for (int i = 2; i < LIM; i++) {
        if (!fatora[i].empty())
            continue;
        for (int j = i; j < LIM; j += i)
            fatora[j].push_back(i);
    }
}

void dale() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), ord(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int v1, int v2) {
        return b[v1] < b[v2];
    });
    int ans = b[ord[0]] + b[ord[1]];
    map<int,int> freq;
    for (int x : a) {
        for (int y : fatora[x]) {
            if (++freq[y] >= 2) {
                ans = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int x : fatora[a[i]]) freq[x]--;
        for (int x : fatora[a[i] + 1])
            if (freq[x]) ans = min(ans, b[i]);
        for (int x : fatora[a[i]]) freq[x]++;
    }

    int idx = ord[0];
    set<int> primos;
    for (int i = 0; i < n; i++){
        if (i == idx) continue;

        for (int x : fatora[a[i]])
            primos.insert(x);
    }

    for (int x : primos){
        int v = x - (a[idx] % x);
        if (v == x) v = 0;
        ans = min(1LL * ans, 1LL * v * b[idx]);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    sieve();
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}
