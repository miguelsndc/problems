#include <bits/stdc++.h>
using namespace std;
const int ms = 205;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    cout << tt << '\n';
    while(tt--) {
        string s; cin >> s;
        int grid[ms][ms];
        memset(grid, 0, sizeof grid);
        int cur_r = 100, cur_c = 0, orientation = 0;
        int min_r = 100, max_r = 100, max_c = 0;
        grid[cur_r][cur_c] = 1;
        for (char c: s) {
            if (c == 'R') orientation = (orientation + 1) % 4;
            else if (c == 'L') orientation = (orientation + 3) % 4;
            else if (c == 'B') orientation = (orientation + 2) % 4;
            
            if (orientation == 0) cur_c++;
            else if (orientation == 1) cur_r++;
            else if (orientation == 2) cur_c--;
            else cur_r--;
            
            grid[cur_r][cur_c] = 1;
            min_r = min(min_r, cur_r);
            max_r = max(max_r, cur_r);
            max_c = max(max_c, cur_c);
        }
        cout << max_r - min_r + 3 << " " << max_c + 2 << '\n';
        for (int i = min_r - 1; i <= max_r + 1; i++) {
            for (int j = 0; j <= max_c + 1; j++) {
                if (grid[i][j]) cout << '.';
                else cout << '#';
            }
            cout << '\n';
        }
    }
}
