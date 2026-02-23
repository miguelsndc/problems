#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main(){
    std::ifstream fin("lemonade.in");
    std::ofstream fout("lemonade.out");
    ios::sync_with_stdio(false);
    fin.tie(nullptr);
    int n; fin >> n;
    vi a; 
    int always = 0;
    for (int i = 0; i < n; i++) {
        int x; fin >> x;
        if (x >= (n - 1)) {
            always++;
        } else {
            a.push_back(x);
        }
    }
    sort(all(a));
    for (int i = a.size() - 1; i >= 0; i--) {
        if (always <= a[i]) {
            always++;
        } else {
            break;
        }
    }
    fout << always << '\n';
}