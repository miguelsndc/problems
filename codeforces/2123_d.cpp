#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int c = count(all(s), '1');
        if (k > n / 2 or (k >= c)) {
            cout << "Alice\n";
            continue;
        } else {
            cout << "Bob\n";
        }
    }
}