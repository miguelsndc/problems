#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x) ^ RANDOM; }
};
void dale() {
    int n, m;
    cin >> n >> m;
    gp_hash_table<int, int, chash> mp;
    int stop = n + 1;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        if (b >= a) {
            int d = b - a;
            if (d == 0) stop = min(stop, a);
            mp[d] = max(mp[d], a);
        }
    }
    int mex = 0;
    while(mp.find(mex) != mp.end() and mp[mex] > stop - 1) mex++;
    cout << mex + n + 1 << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}