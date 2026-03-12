    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    using ii = pair<ll, ll>;
    #define sz(x) ((int)(x).size())
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        ll n; cin >> n;
        ll cur = n;
        auto cmp = [&] (const ii&left, const ii&right) {
            return left.first * left.second > right.first * right.second;
        };
        priority_queue<ii, vector<ii>, decltype(cmp)> pq(cmp);
        for (ll i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int cnt = 0;
                while(n % i == 0) n /= i, cnt++;
                pq.push({i, 1});
            }
        }
        if (n > 1) pq.push({n, 1});
        int ans = 0;
        while (cur > 1 and pq.size()) {
            auto [factor, power] = pq.top(); pq.pop();
            ll num = pow(factor, power);
            if (cur % num == 0) cur /= num, pq.push({factor, power + 1}), ans++;
        }
        cout << ans << '\n';
    }
