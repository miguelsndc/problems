#include <bits/stdc++.h>
using ll = long long;
using namespace std;
map<int, int> cnt;
vector<int> pts;
int n, tam;
bool arrocha(int p_novo, bool remover) {
    // cout << p_novo << ' ' << remover << '\n';
    // cout.flush();
    vector<int> used;
    bool da = true;
    for (int p : pts) {
        int d = abs(p_novo - p);
        if (remover) {
            if (cnt[d] > 0) {
                if (--cnt[d] == 0) cnt.erase(d);
                used.push_back(d);
            } else {
                da = false;
                break;
            }
        } else {
            cnt[d]++;
        }
    }
    if (!da && remover) {
        for (int d : used) cnt[d]++;
        return false;
    }
    return true;
}

bool resolve() {
    if (pts.size() == n) return true;
    if (cnt.empty()) return true;
    int dmax = cnt.rbegin()->first;

    if (arrocha(dmax, true)) {
        pts.push_back(dmax);
        if (resolve()) return true;
        pts.pop_back();
        arrocha(dmax, false);
    }
    int p2 = tam - dmax;
    if (p2 != dmax) {
        if (arrocha(p2, true)) {
            if (resolve()) return true;
            pts.push_back(p2);
            pts.pop_back();
            arrocha(p2, false);
        }
    }
    return false;
}

void dale() {
    cin >> n; 
    int m = n * (n-1)/2;
    cnt.clear();
    pts.clear();
    for (int i = 0; i < m; i++) {
        int d; cin >> d;
        if (d > 0) cnt[d]++;
    }
    tam = cnt.rbegin()->first;
    if (--cnt[tam] == 0) cnt.erase(tam);
    pts.push_back(0);
    pts.push_back(tam);
    resolve();
    sort(pts.begin(), pts.end());
    for (int i = 0; i < n; i++) {
        cout << pts[i] << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int tt; cin >> tt;
    while (tt--) dale();
    return 0;
}