#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int S, B;
    while((cin >> S >> B) and (S != 0 or B != 0)) {
        vector<int> left(S + 2, -1), right(S + 2, -1);
        for (int i = 1; i <= S; i++) {
            left[i] = i - 1;
            right[i] = i + 1;
        }
        left[1] = right[S] = -1;    
        /*
            1 2 3 4 5 6 7 8 9 10
            1 6 7 8 9 10
            1 10
            10

        */
        for (int i = 0; i < B; i++) {
            int l, r; cin >> l >> r;
            if (left[l] != -1) {
                right[left[l]] = right[r];
            }
            if (right[r] != -1) {
                left[right[r]] = left[l];
            }
            cout << (left[l] == -1 ? "*" : to_string(left[l])) << ' ';
            cout << (right[r] == -1 ? "*" : to_string(right[r])) << '\n';
        }
        cout << "-\n";
    }
}
