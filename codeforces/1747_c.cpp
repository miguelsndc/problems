#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void dale() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    ll s = *min_element(a.begin(), a.end());
    if (a[0] == s) {
        cout << "Bob\n";
    } else { 
        cout << "Alice\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) dale();
}