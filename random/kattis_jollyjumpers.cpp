#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while((cin >> n)) {
		vector<int> a(n), tem(n);
		tem[0] = true;
		for (auto &i: a) cin >> i;
		for (int i = 0; i + 1 < n; i++) {
			int val = abs(a[i + 1] - a[i]);
            if (val >= 1 and val < n) {
                tem[val] = true;
            }
        }
        if (count(tem.begin(), tem.end(), 0) > 0) {
            cout << "Not jolly\n";
        } else {
            cout << "Jolly\n";
        }
	}
}

