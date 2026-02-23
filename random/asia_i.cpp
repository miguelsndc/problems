#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define sz(x) ((int)(x.size()))

void dale() {
    int n; cin >> n;
    vector<ll> dist(n - 1), a(n), ps(n + 1);
    for (ll& i : dist) cin >> i;
    for (int i = 0; i < n - 1; i++) a[i + 1] = a[i] + dist[i];
    for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + a[i];
    ll todos = 0;
    for (int i = 0; i < n; i++) {
        ll cur = -(n - i) * a[i] + ps[n] - ps[i];
        todos += cur;
    }
    vector<ll> ans(n);
    
    ll sum_left = 0, cnt_left = 0;
    ll sum_right = 0, cnt_right = 0;

    auto comp1 = [&](int i, int j) {
        return a[i] < a[j];
        };
    auto comp2 = [&](int i, int j) {
        return a[i] > a[j];
        };
    priority_queue<int, vector<int>, decltype(comp1)> left(comp1);
    priority_queue<int, vector<int>, decltype(comp2)> right(comp2);
    
    for (int i = 0; i < (n / 2); i++) {
        left.push(i);
        sum_left += a[i];
        cnt_left++;
    }
    for (int i = n / 2; i < n; i++) {
        right.push(i);
        sum_right += a[i];
        cnt_right++;
    }
    
    ans.back() = todos;
    
    auto get_contrib = [&](int idx) {
        return a[idx] * (cnt_left - cnt_right) - sum_left + sum_right;
    };

    for (int i = n - 2; i >= 0; i--) {
        ll c1 = 2e18, c2 = 2e18;
        if (left.size()) c1 = get_contrib(left.top());
        if (right.size()) c2 = get_contrib(right.top());
        if (c1 < c2) {
            todos -= c1;
            sum_left -= a[left.top()];
            cnt_left--;
            left.pop();
        }
        else {
            todos -= c2;
            sum_right -= a[right.top()];
            cnt_right--;
            right.pop();
        }
        ans[i] = todos;
    }
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << " \n"[i == (sz(ans) - 1)];
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}