#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int get(char x) {
    if (x == ' ')
        return 36;
    else if (x >= 'A' and x <= 'Z')
        return (int)(x - 'A');
    return 26 + (x - '0');
}
char revget(int x) {
    if (x == 36)
        return ' ';
    else if (x >= 0 and x <= 25)
        return char(x + 'A');
    return char(x - 26 + '0');
}
void dale() {
    int n;
    cin >> n;
    vector mat(n, vector<int>(n));
    for (auto &v : mat)
        for (auto &x : v) cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    getline(cin, s);
    vector<int> v;
    for (char c : s) v.push_back(get(c));
    while (v.size() % n != 0) {
        v.push_back(36);
    }
    vector<vector<int>> vectors;
    vector<int> cur;
    for (char c : v) {
        cur.push_back(c);
        if (cur.size() == n) {
            vectors.push_back(cur);
            cur.clear();
        }
    }
    string res;
    for (const auto &vec : vectors) {
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i] += (vec[j] * mat[i][j]) % 37;
                ans[i] %= 37;
            }
        }
        string sss;
        for (int x : ans) sss.push_back(revget(x));
        res += sss;
    }
    cout << res << "\n";
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1;  // cin >> tt;
    while (tt--) dale();
}