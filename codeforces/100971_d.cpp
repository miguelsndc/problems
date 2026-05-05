#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct pii {
    int first, second, id;
    bool operator<(const pii& o) const {
        return first < o.first;
    }
};

void slve() {
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].id = i;
    }
    sort(a.begin(), a.end());
    vector<int> left(n, -1), right(n, -1), perto(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (st.size() > 0 and a[st.top()].second <= a[i].second) st.pop();
        if (st.size() > 0) left[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() > 0 and a[st.top()].second <= a[i].second) st.pop();
        if (st.size() > 0) right[i] = st.top();
        st.push(i);
    }
    for (int i = 0; i < n; i++) {
        if (left[i] == -1) {
            perto[i] = right[i];
            continue;
        }
        if (right[i] == -1) {
            perto[i] = left[i];
            continue;
        }
        int dl = abs(a[i].first - a[left[i]].first);
        int dr = abs(a[i].first - a[right[i]].first);
        if (dl < dr) {
            perto[i] = left[i];
        }
        else if (dl == dr) {
            perto[i] = (a[left[i]].second > a[right[i]].second ? left[i] : right[i]);
        }
        else {
            perto[i] = right[i];
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (perto[i] == -1) {
            ans[a[i].id] = -1;
        }
        else {
            ans[a[i].id] = a[perto[i]].id + 1;
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) slve();
}