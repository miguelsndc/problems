#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#define ll long long
#define pii pair<int, int>

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        vector<string> notes = {"C",  "C#", "D",  "D#", "E",  "F",
                                "F#", "G",  "G#", "A",  "A#", "B"};
        vector<string> v = notes;
        for (string &c: notes) v.push_back(c);
        // d(n1, n2) = 4 and d(n2, n3) = 3 -> major
        // d(n1, n2) = 3 and d(n2, n3) = 4 -> minor
        string low, mid, high; cin >> low >> mid >> high;
        int a = -1, b = -1, c = -1;
        for (int i = 0; i < sz(v); i++) {
            if (v[i] == low and a == -1) a = i;
            else if (v[i] == mid and a != -1 and b == -1) b = i;
            else if (v[i] == high and a != -1 and b != -1 and c == -1) c = i;
        }
        if ((b - a) == 4 and (c - b) == 3) {
            cout << "Major triad\n";
        } else if ((b - a) == 3 and (c - b) == 4) {
            cout << "Minor triad\n";
        } else {
            cout << "Dissonance\n";
        }
    }
}