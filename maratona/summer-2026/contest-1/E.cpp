#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    while((cin >> n) and n) {
        vector<int> a(n), v(n), st;
        for (int&i: a) cin >> i, --i;
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == p) {
                p++;
                continue;
            }
            while(st.size() and st.back() == p) {
                st.pop_back();
                p++;
            } 
            st.push_back(a[i]);
        }
        bool ok = true;
        while(st.size() and ok) {
            ok &= st.back() == p++;
            st.pop_back();
        }
        if (ok) cout << "yes\n";
        else cout << "no\n";
    }
}