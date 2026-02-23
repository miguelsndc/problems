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
    int tt; cin >> tt;
    while(tt--) {
        int n; cin >> n;
        vi p(n);
        for (int &i: p) cin >> i;
        set<int> s;
        for (int i = 1; i <= n; i++) s.insert(i);
        for (int i = 0; i < n; i++) {
            if (p[i] != 0) s.erase(p[i]);
        }
        for (int i = 0; i < n; i++) {
            if (p[i] == 0) {
                p[i] = *s.rbegin();
                s.erase(p[i]);
            }
            // cout << p[i] << " \n"[i == n - 1]; 
        }
        int left = 0, any = false;
        for (int i = 0; i < n; i++) {
            int x = i + 1;
            if (p[i] != x) {
                any = true;
                left = i;
                break;
            }
        }
        int right = 0;
        for (int i = n - 1; i >= 0; i--) {
            int x = i + 1;
            if (p[i] != x) {
                any = true;
                right = i;
                break;
            }
        }
        if (!any) {
            cout << 0 << '\n';
        } else {
            cout << right - left + 1 << '\n';
        }
    }
}