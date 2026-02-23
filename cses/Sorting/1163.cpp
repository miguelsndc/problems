#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U>
inline bool chmax(T& a, const U& b) {
    return a < b ? (a = b, true) : false;
}
void dale() {
    int k, n;
    cin >> k >> n;
    set<int> s{0, k};
    multiset<int> diffs;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto lb = s.lower_bound(x);
        vector<int> to_erase;
        if (lb != s.begin()) {
            int p = *prev(lb);
            if (diffs.size() and lb != s.end()) {
                to_erase.push_back(abs(p - *lb));
            }
            diffs.insert(abs(p - x));
        }
        diffs.insert(abs(*lb - x));
        for (int x : to_erase)
            if (diffs.find(x) != diffs.end()) diffs.erase(diffs.find(x));
        s.insert(x);

        cout << *diffs.rbegin() << ' ';
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}