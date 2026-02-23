#include <bits/stdc++.h>
using namespace std;
namespace rg = ranges;
typedef long long ll;
typedef pair<int, int> pii;
#define sz(x) (int((x).size()))
ll x = 1, mx = 1e18;
vector<ll> values{1};
void dale() {
    ll t; cin >> t;
    int cnt = 0;
    while(t > 0) {
        ll val = *prev(rg::upper_bound(values, t));
        t -= val;
        cnt++;
    }
    cout << cnt - 1<< '\n';
}
int main(){
    while(values.back() < mx) {
        x <<= 1;
        values.push_back(values.back() + x);
    }
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while(tt--) dale();
 }