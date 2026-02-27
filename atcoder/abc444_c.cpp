#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll L, int n, const vector<int> &a) {
  int l = 0, r = n - 1;
  while(l <= r) {
    if (a[r] == L) r--; 
    else if (a[r] > L) return false;
    else {
      if (l < r and (ll)a[l] + a[r] == L) {
        l++; r--;
      } else {
        return false;
      }
    }
  }
  return true;
}
int main() {
  cin.tie(0)->sync_with_stdio(false); 
  int n; cin >> n;
  vector<int> a(n);
  for (auto &i:a) cin >> i;
  sort(a.begin(), a.end()); set<ll> valido;
  if (check(a.back(), n, a)) valido.insert(a.back());
  if (check(a.front() + a.back(), n, a)) valido.insert(a.front() + a.back());
  for (int x: valido) cout << x << ' ';
}