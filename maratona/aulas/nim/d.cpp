#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

/*
    nim normal
    cada coluna é um jogo

    cada jogo:
        2 pilhas p1 e p2
        restricoes  
            0 <= |p1| <= (linhas - 2)
            0 <= |p2| <= (linhas - 2)
            |p1| + |p2| <= linhas - 2
            claim: |p1| + |p2| ja encoda a restricao de atravessamento
        quem tiver tamanho = 0 quando |p1| + |p2| = linhas - 2 perde

*/ 

string slve() {
    int n; cin >> n;
    vector<int> w(n), b(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int nim = 0;
    for (int i = 0; i < n; i++) {
        int gap = b[i] - w[i] - 1;
        nim ^= gap;
    }
    return (nim != 0 ? "white": "black");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cout << "Case " << t << ": " << slve() << " wins\n";
    }
}