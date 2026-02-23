#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool adj(int face_a, int face_b) {
    return face_a != face_b && face_a + face_b != 7;
}
void dale() {
    int n;
    cin >> n;
    vector<int> cost(7);
    int p; cin >> p;
    for (int f = 1; f <= 6; f++)  cost[f] = (p != f);
    for (int i = 1; i < n; i++) {
        cin >> p;
        vector<int> novo(7, 1e9);
        for (int atual = 1; atual <= 6; atual++) {
            for (int anterior = 1; anterior <= 6; anterior++) {
                if (adj(atual, anterior)) {
                    novo[atual] = min(novo[atual], cost[anterior] + (p != atual));
                }
            }
        }
        cost = novo;
    }
    int ans = 1e9;
    for (int i = 1; i <= 6; i++) ans = min(ans, cost[i]);

    cout << ans << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt = 1; cin >> tt;
    while (tt--) dale();
}