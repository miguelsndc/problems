#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
typedef pair<int, int> pii;
void dale() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto get = [&](vector<int> &a) -> int {
        // sort(a.begin(), a.end());
        nth_element(a.begin(), a.end() - k, a.end());
        vector<int> topk(a.end() - k, a.end());
        nth_element(topk.begin(), topk.begin() + k / 2, topk.end());
        return accumulate(topk.begin(), topk.begin() + k / 2, 0ll);
    };
    int mx = *max_element(a.begin(), a.end());
    int ans = 0;
    for (int b = 1; b <= mx; b++) {
        vector<int> novo;
        for (int i = 0; i < n; i++) {
            int has = (a[i] / b);
            int sobra = a[i] % b;
            for (int j = 0; j < has; j++) novo.push_back(b);
            if (sobra > 0) novo.push_back(sobra);
        }
        if (novo.size() >= k) {
            ans = max(ans, get(novo));
        }
    }
    cout << ans << '\n';
}
int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}