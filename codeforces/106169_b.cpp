#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) ((int)(x).size())
void dale() {
    int n; cin >> n;
    cin.ignore();
    ll ans = 0;
    while(n--) {
        string s; 
        getline(cin, s);
        vector<string> v;
        string aux;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == ' ') v.push_back(aux), aux.clear();
            else aux.push_back(s[i]);
        }
        if (aux.size()) v.push_back(aux);

        if (v.size() == 4 and v[0] == "Set" and v[2] == "to" and v[3] == "answer") {
            ans += v[1].size();
        }
    }
    cout << ans << '\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}