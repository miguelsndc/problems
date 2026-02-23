#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n, k;
    int x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    int ans = 0;
    vector<int> v(n);
    v[0] = x;
    deque<int> dq;
    for (int i = 1; i < n; i++) {
        v[i] = ((1ll * a * v[i - 1] + b) % c);
    }
    for (int i = 0; i < n; i++) {
        if (!dq.empty() and dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() and v[dq.back()] > v[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) ans ^= v[dq.front()];
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
#ifdef MIGUEL_DBG
    auto start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
#ifdef MIGUEL_DBG 
    auto end = chrono::high_resolution_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << "Time: " << ms << " ms\n";
#endif
}