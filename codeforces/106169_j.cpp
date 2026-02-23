#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
map<int, int> parent;
int find(int i) {
    if (parent.find(i) == parent.end()) return i;
    return parent[i] = find(parent[i]);
}
void insert(int x) {
    if (parent.find(x) != parent.end()) return;
    parent[x] = find(x + 1);
}
void dale() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    set<int> s;
    vector<int> dup;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int x = n - 1; x >= 0; x--) {
        if (s.count(a[x])) {
            dup.push_back(a[x]);
        } else {
            s.insert(a[x]);
            insert(a[x]);
        }
    }
    for (int x: dup) {
        int next = find(x);
        pq.push((ll)next - x);
        insert(next);
    }
    int ans = s.size();
    while(!pq.empty()) {
        if (k >= pq.top()) k -= pq.top(), ans++;
        pq.pop();
    }
    parent.clear();
    cout << ans << '\n';
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}