#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
const int maxn = (1 << 17) + 10;
int tree[4 * maxn], a[maxn], n, m;
int join(int a, int b, int d) {
    if (n & 1) {
        if (d % 2 == 0) {
            // cout << "depth par\n";
            // cout << "foi or entre: " << a << ' ' << b << endl;
            return a | b;
        } else {
            // cout << "depth impar\n";
            // cout << "foi xor entre: " << a << ' ' << b << endl;
            return a ^ b;
        }
    } else {
        if (d % 2 == 0) {
            // cout << "depth par\n";
            // cout << "foi xor entre: " << a << ' ' << b << endl;
            return a ^ b;
        } else {
            // cout << "depth impar\n";
            // cout << "foi or entre: " << a << ' ' << b << endl;
            return a | b;
        }
    }
}
void build(int l, int r, int v = 0, int depth = 0) {
    if (l == r) {
        tree[v] = a[l];
    } else {
        int mid = (l + r) / 2;
        build(l, mid, v * 2 + 1, depth + 1);
        build(mid + 1, r, v * 2 + 2, depth + 1);
        tree[v] = join(tree[v * 2 + 1], tree[v * 2 + 2], depth);
    }
}
void update(int pos, int val, int l, int r, int v = 0, int depth = 0) {
     if (l == r) {
        tree[v] = val;
    } else {
        int mid = (l + r) / 2;
        if (pos <= mid) {
            update(pos, val, l, mid, v * 2 + 1, depth + 1);
        } else {
            update(pos,val, mid + 1, r, v * 2 + 2, depth + 1);
        }
        tree[v] = join(tree[v * 2 + 1], tree[v * 2 + 2], depth);
    }
}

void solve() { 
    cin >> n >> m;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    build(0, (1 << n) - 1);
    while(m--) {
        int p, b; cin >> p >> b;
        update(p - 1, b, 0, (1 << n) - 1);
        cout << tree[0] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;  // cin >> tt;
    while (tt--) solve();
}
