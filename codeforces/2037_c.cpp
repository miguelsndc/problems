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
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        if (n <= 4) {
            cout << "-1\n";
            continue;
        }
        set<int> odds, evens;
        for (int i = 1; i <= n; i += 2) odds.insert(i);
        for (int i = 2; i <= n; i += 2) evens.insert(i);

        odds.erase(5);
        evens.erase(4);
        for (int x: odds) cout << x << ' ';
        cout << 5 << ' ' << 4 << ' ';
        for (int x: evens) cout << x << ' ';
        cout << '\n';
    }
}