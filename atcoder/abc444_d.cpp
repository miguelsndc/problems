#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = *max_element(a.begin(), a.end());
  vector<int> d(mx + 1);
  for (auto x : a) d[0]++, d[x]--;

  for (int i = 1; i <= mx; i++) {
    d[i] += d[i - 1];
  }
  vector<int> ans;
  int carry = 0;
  for (int i = 0; i <= mx; i++) {
    if (d[i] != 0) {
      ans.push_back(d[i]);
    } else {
      break;
    }
  }
  carry = ans[0] / 10;
  ans[0] %= 10;
  for (int i = 1; i < (int)(ans.size()); i++) {
    ans[i] += carry;
    carry = ans[i] / 10;
    ans[i] %= 10;
  }
  if (carry > 0) ans.push_back(carry);
  reverse(ans.begin(), ans.end());
  for (int x : ans) cout << x;
}