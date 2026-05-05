#include <bits/stdc++.h>
using namespace std;
const int ms = 5e5 + 5, inf = 1e9 + 1, MAX_NODES = 1e7 + 1;
struct Node;
Node *mem_pool;
int mem_ptr = 0;
struct Node {
	int val = inf;
	Node *l, *r;
	Node (int x): val(x), l(nullptr), r(nullptr) {}
	Node (Node *ll, Node *rr) {
		l = ll, r = rr;
		val = inf;
		if (l) val = min(val, l->val);
		if (r) val = min(val, r->val);
	}
	Node (Node *cp): val(cp->val), l(cp->l), r(cp->r) {}
	void *operator new(size_t) {
		return &mem_pool[mem_ptr++];
	}
};
int n, cnt = 1;
int a[ms]; Node *roots[ms];

Node *update(Node *node, int val, int pos, int l = 1, int r = n) {
	if (l == r) return new Node(val);
	int mid = (l + r) / 2;
	Node *esq = node ? node->l: nullptr;
	Node *dir = node ? node->r: nullptr;
	if (pos > mid) {
		auto novo = update(dir, val, pos, mid + 1, r);
		return new Node(esq, novo);
	}
	auto novo = update(esq, val, pos, l, mid);
	return new Node(novo, dir);
}

int query(Node *node, int a, int b, int l = 1, int r = n) {
	if (!node or l > b or r < a) return inf;
	if (l >= a and r <= b) return node->val;
	int mid = (l + r) / 2;
	auto left = query(node->l, a, b, l, mid);
	auto right = query(node->r, a, b, mid + 1, r);
	return min(left, right);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mem_pool = (Node*)malloc(sizeof(Node) * MAX_NODES);
    int m;
    if (!(cin >> n >> m)) return 0;
    roots[0] = nullptr;
    vector<int> distinct;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        distinct.push_back(a[i]);
    }
    sort(distinct.begin(), distinct.end());
    distinct.erase(unique(distinct.begin(), distinct.end()), distinct.end());
    vector<int> last(distinct.size() + 1, 0);
    for (int i = 1; i <= n; i++) {
        int id = lower_bound(distinct.begin(), distinct.end(), a[i]) - distinct.begin() + 1;
        if (last[id] == 0) {
            roots[i] = roots[i - 1];
        } else {
            int pos = last[id];
            int val = i - pos;
            roots[i] = update(roots[i - 1], val, pos);
        }
        last[id] = i; 
    }
    
    while(m--) {
        int l, r; cin >> l >> r;
        int res = query(roots[r], l, r);
        cout << (res == inf ? -1 : res) << '\n';
    }

    free(mem_pool);
    return 0;
}
