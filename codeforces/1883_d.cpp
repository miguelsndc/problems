#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    multiset<int> L, R;
    while(q--) {
        char c; int l, r; cin >> c; cin >> l >> r;
        if (c == '+') {
            L.insert(l);
            R.insert(r);
        } else {
            L.erase(L.find(l));
            R.erase(R.find(r));
        }

        if (L.size() > 0) {
            int maxL = *L.rbegin();
            int minR = *R.begin();
            if (maxL > minR) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
}