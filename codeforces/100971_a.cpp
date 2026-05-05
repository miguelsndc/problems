#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int comp(vector<string>& g) {
    int n = (int)g.size(), m = (int)(g[0].size());
    vector<vector<bool>> vis(n, vector<bool>(m));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] or g[i][j] == '#') continue;
            cnt++;
            queue<pii> q;
            vis[i][j] = true;
            q.emplace(i, j);
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nr = r + dx[d];
                    int nc = c + dy[d];
                    if (!(nr >= 0 and nr < n and nc >= 0 and nc < m)) continue;
                    if (vis[nr][nc] or g[nr][nc] == '#') continue;
                    vis[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }
    }
    return cnt;
}

/*
    faz um bfs a partir de um ponto qualquer, marca os caras q achou
    dps olha pros ? se eu visitei ele quero que seja terra, se nao agua
    pq nao perco nada
    se tiver mais de 1 componente tenho 2 ilhas: gg.
    dps olha pra toda ? dnv
    se eu puder tirar esse cara e ainda ter 1 componente ent ele nao eh essencial
    posso tirar ele e fds, entao ambiguo
    se eu preciso dele (articulacao) pra ter uma ilha entao ok 
*/

void slve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (auto& s : g) cin >> s;
    vector<pii> pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '?') pos.emplace_back(i, j);
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<pii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                vis[i][j] = true;
                q.emplace(i, j);
                break;
            }
        }
    }
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (!(nr >= 0 and nr < n and nc >= 0 and nc < m)) continue;
            if (vis[nr][nc] or g[nr][nc] == '#') continue;
            vis[nr][nc] = true;
            q.emplace(nr, nc);
        }
    }
    for (auto [i, j]: pos) {
        if (vis[i][j]) g[i][j] = '.';
        else g[i][j] = '#';
    }
    int c = comp(g);
    if (c > 1) {
        cout << "Impossible\n";
        return;
    }

    for (auto [i, j]: pos) if (g[i][j] == '.') {
        g[i][j] = '#';
        if (comp(g) == 1) {
            cout << "Ambiguous\n";
            return;
        }
        g[i][j] = '.';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}