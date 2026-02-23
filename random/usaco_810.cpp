#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    ifstream fin ("reststops.in");
    ofstream fout ("reststops.out");
    fin.sync_with_stdio(false);
    fin.tie(nullptr);
    int L, N, rf, rb;
    fin >> L >> N >> rf >> rb;
    vector<ll> x(N), c(N), good(N);
    for (int i = 0; i < N; i++) {
        fin >> x[i] >> c[i];
    }
    ll mx = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (c[i] > mx) {
            good[i] = true;
            mx = c[i];
        }
    }

    ll ans = 0, prev = 0;
    for (int i = 0; i < N; i++) {
        if (good[i]) {
            ans += ((x[i] - prev) * rf - (x[i] - prev) * rb) * c[i];
            prev = x[i];
        }
    }
    fout << ans << '\n';
}