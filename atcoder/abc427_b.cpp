#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int somadigitos(int x) {
    int soma = 0;
    while(x > 0) {
        int k = x % 10;
        soma += k;
        x /= 10;
    }
    return soma;
}
void dale() {
    int n; cin >> n;
    vector<ll> a = {1};
    for (int i = 0; i < n; i++) {
        a.push_back(a.back() + somadigitos(a.back()));
    }
    a.pop_back();
    cout << a.back();
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}