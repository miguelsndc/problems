#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

struct MinQueue: deque<int> {
    int get_min() {
        return front();
    }
    void add(int x) {
        while(!empty() and back() > x) pop_back();
        push_back(x);
    }
    void remove(int x) {
        if (!empty() and front() == x) pop_front();
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    ll x, a, b, c; cin >> x >> a >> b >> c;
    vector<ll> v(n);
    v[0] = x;
    for (int i = 1; i < n; i++) {
        v[i] = (1ll * a * v[i - 1] + b) % c; 
    }
    ll xs = 0, ans = 0;
    for (int i = 0; i < k; i++) xs ^= v[i];
    ans = xs;
    for (int i = k; i < n; i++) {
        xs ^= v[i];
        xs ^= v[i - k];
        ans ^= xs;
    }
    cout << ans << '\n';
}