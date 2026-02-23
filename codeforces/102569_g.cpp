#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
/*
1 2 3 4 5
5 4 3 2 1
*/
int partition(vector<int>& a, int l, int r) {
    int pivot = a[uniform(l, r)], i = l, j = r + 1;
    while (i < j) {
        i++;
        while (1) {
            cout << "? " << i << ' ' << pivot << endl;
            char ans; cin >> ans;
            if (ans != '<') break;
            i++;
        }
        j--;
        while (1) {
            cout << "? " << j << ' ' << pivot << endl;
            char ans; cin >> ans;
            if (ans != '>') break;
            j--;
        }
        swap(a[i], a[j]);
    }
    swap(a[i], a[j]);
    swap(a[pivot], a[j]);
    return j;
}
// 1 2 3 4 5
// 5 4 3 2 1
void quick_sort(vector<int>& a, int l, int r) {
    if (l < r) {
        int s = partition(a, l, r);
        quick_sort(a, l, s - 1);
        quick_sort(a, s + 1, r);
    }
}
void dale() {
    int n; cin >> n;
    vector<int> a(n + 1);
    iota(a.begin(), a.end(), 0);
    quick_sort(a, 1, n);
    cout << "! ";
    for (int x: a) cout << x << ' ';
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; // cin >> tt;
    while(tt--) dale();
}