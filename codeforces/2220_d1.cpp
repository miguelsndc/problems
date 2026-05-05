#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

void slve() {
    int n; cin >> n;
    
    auto pede = [&] (vector<int> &a) {
        cout << "? " << a.size() << ' ';
        for (int x: a) cout << x << ' ';
        cout << endl;
        int res; cin >> res;
        if (res == -1) exit(0);
        return res;
    };
    
    vector<int> ans;
    map<int, int> memo;
    
    auto query = [&] (int mid) {
        if (mid == 2 * n + 1) return 3;
        if (memo.count(mid)) return memo[mid];
        
        vector<int> q1, q2;
        for (int i = 1; i <= mid; i++) q1.push_back(i);
        for (int i = mid + 1; i <= 2 * n + 1; i++) q2.push_back(i);
        
        auto s = pede(q1), t = pede(q2);
        int res = 0;
        
        if (s > t) {
            res = 1;
        } else if (s < t) {
            res = 2;
        } else {
            if ((q1.size() - s) % 2 == 1) res = 3;
            else res = 0;
        }
        
        return memo[mid] = res;
    };
    
    for (int _ = 0; _ < 3; _++) {
        int l = 1, r = 2 * n + 1, ind = -1;
        while(l <= r) {
            int m = (l + r) / 2;
            
            int total_especiais = query(m);
            int ja_achados = 0;
            
            for(int x : ans) {
                if (x <= m) ja_achados++;
            }
            
            if (total_especiais - ja_achados > 0) {
                ind = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        ans.push_back(ind);
    }
    
    cout << "! " << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    while(tt--) slve();
}