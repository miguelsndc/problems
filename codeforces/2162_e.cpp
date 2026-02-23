#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Mex {
private:
    map<int, int> frequency;
    set<int> missing_numbers;
    vector<int> A;

public:
    Mex(vector<int> const& A) : A(A) {
        for (int i = 0; i <= A.size(); i++)
            missing_numbers.insert(i);

        for (int x : A) {
            ++frequency[x];
            missing_numbers.erase(x);
        }
    }

    int mex() {
        return *missing_numbers.begin();
    }

    void update(int idx, int new_value) {
        if (--frequency[A[idx]] == 0)
            missing_numbers.insert(A[idx]);
        A[idx] = new_value;
        ++frequency[new_value];
        missing_numbers.erase(new_value);
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), freq(n + 1);
        for (int &i: a) cin >> i, freq[i]++;
        int x = -1;
        for (int i = 1; i <= n; i++) if (freq[i] == 0) {
            x = i;
            break;
        }
        if (x == -1) {
            for (int i = 0; i < k; i++) cout << a[n - 3 + (i % 3)] << ' ';
            cout << '\n';
        } else {
            int y = -1;
            for (int i = 1; i <= n; i++) if (i != x and i != a.back()) {
                y = i;
                break;
            }
            vector<int> v = {x, y, a.back()};
            for (int i = 0; i < k; i++) cout << v[i % 3] << ' ';
            cout << '\n';
        }
    }
}