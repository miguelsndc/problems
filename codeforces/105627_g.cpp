#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
int brute(int n) {
    vector<int> p(n + 1);
    rg::iota(p, 0);
    int ans = 0;
    do {
        vector<int> a = p, b = p;
        while(true) {
            for (int i = n; i >= 2; i--) {
                if (a[i] < a[i / 2]) swap(a[i], a[i / 2]);
            }
            if (rg::equal(a, b)) {
                break;
            }
            b = a;
        }
        if (is_sorted(a.begin() + 1, a.end())) ans++;
    } while (next_permutation(p.begin() + 1, p.end()));
    return ans;
}
int brute2(int n) {
    vector<int> p(n + 1);
    rg::iota(p, 0);
    int ans = 0;
    do {
        if (is_heap(p.begin() + 1, p.end())) ans++;
    } while (next_permutation(p.begin() + 1, p.end()));
    return ans;
}
void dale() {
    int n; cin >> n;
    cout << n << ' ' << brute(n) << ' ' << brute2(n) << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
}