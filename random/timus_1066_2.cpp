#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
double a;
const double eps = 1e-9;

bool thomas(vector<double>& a,
            vector<double>& b,
            vector<double>& c,
            vector<double>& d,
            vector<double>& x) {
    int k = b.size();
    if (k == 0) return true;

    vector<double> cp(k);
    vector<double> dp(k);

    double denom = b[0];
    if (fabs(denom) < eps) return false;
    cp[0] = c[0] / denom;
    dp[0] = d[0] / denom;

    for (int i = 1; i < k; i++) {
        denom = b[i] - a[i] * cp[i - 1];
        cp[i] = (i == k - 1) ? 0.0 : c[i] / denom;
        dp[i] = (d[i] - a[i] * dp[i - 1]) / denom;
    }
    x[k - 1] = dp[k - 1];
    if (x[k - 1] < -eps) return false;

    for (int i = k - 2; i >= 0; i--) {
        x[i] = dp[i] - cp[i] * x[i + 1];
        if (x[i] < -eps) return false;
    }
    return true;
}

bool check(double m) {
    if (m < -eps) return false;
    int k = n - 2;
    if (k <= 0) return true;
    vector<double> princ(k, 2.0), super(k, -1.0), sub(k, -1.0);
    vector<double> rhs(k, -2.0);
    rhs[0] += a;
    rhs[k - 1] += m;
    vector<double> x(k);
    return thomas(sub, princ, super, rhs, x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    cin >> a;

    double l = 0, r = 1e9;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2.0;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << setprecision(2) << fixed << r << '\n';
}