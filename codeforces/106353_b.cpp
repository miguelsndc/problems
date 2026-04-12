#include <bits/stdc++.h>
using namespace std;
/*
    um n não é splitavel se:
    - consigo formar duas pilhas p1 e p2 de moedas tal que soma(p1) + soma(p2) = n
    e não consigo formar (soma(p1) - soma(p2)) / 2 com as moedas da maior pilha pra todo x >= n / 2
    20 2 | 10 10
*/
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    if (n & 1) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) cout << 1 << ' ';
        exit(0);
    }
    if (n % 4 == 0) {
        cout << "splittable\n";
        exit(0);
    }

    if (n % 4 == 2) {
        vector<int> ans;
        while(n > 0) n -= 2, ans.push_back(2);
        cout << ans.size() << '\n';
        for (int x: ans) cout << x << ' ';
    }
}