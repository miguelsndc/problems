#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9;
void bop()
{
    int n;
    cin >> n;
    vector<int> to(10 * n, -1);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        int c = idx % 10, x = idx / 10;
        for (int cc = max(1, c); cc <= 9; cc++) {
            int xx = (x * 10 + cc) % n;
            int idx2 = 10 * xx + cc;
            if (to[idx2] != -1) {
                break;
            }
            q.push(idx2);
            to[idx2] = idx;
            if (xx == 0) {
                vector<int> ans;
                int cur = idx2;
                while (cur != 0) {
                    ans.push_back(cur % 10);
                    cur = to[cur];
                }
                reverse(ans.begin(), ans.end());
                for (int x : ans)
                    cout << x;
                return;
            }
        }
    }
    cout << -1;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; // cin >> tt;
    while (tt--)
        bop();
}