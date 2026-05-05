#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_NODES = 1e7 + 5;
struct Node;
Node *mem_pool;
int mem_ptr = 0;

struct Node {
	ll val;
	Node *l, *r;
	Node (ll x): val(x), l(nullptr), r(nullptr) {}
	Node (Node *ll, Node *rr) {
		l = ll, r = rr;
		val = 0;
		if (l) val += l->val;
		if (r) val += r->val;
	}
	Node (Node *cp): val(cp->val), l(cp->l), r(cp->r) {}
	void *operator new(size_t) {
		return &mem_pool[mem_ptr++];
	}
};

const int ms = 2e5 + 5;
int n, cnt = 1;
ll a[ms]; Node *roots[ms];

Node *build(int l = 1, int r = n) {
	if (l == r) return new Node(a[l]);
	int mid = (l + r) / 2;
	return new Node(build(l, mid), build(mid + 1, r));
}

Node *update(Node *node, int val, int pos, int l = 1, int r = n) {
	if (l == r) return new Node(val);
	int mid = (l + r) / 2;
	if (pos > mid) {
		auto novo = update(node->r, val, pos, mid + 1, r);
		return new Node(node->l, novo);
	}
	auto novo = update(node->l, val, pos, l, mid);
	return new Node(novo, node->r);
}

ll query(Node *node, int a, int b, int l = 1, int r = n) {
	if (l > b or r < a) return 0;
	if (l >= a and r <= b) return node->val;
	int mid = (l + r) / 2;
	auto left = query(node->l, a, b, l, mid);
	auto right = query(node->r, a, b, mid + 1, r);
	return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	mem_pool = (Node *)malloc(sizeof(Node) * MAX_NODES);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	roots[cnt++] = build();
	while(q--) {
		int t; cin >> t;
		if (t == 1) {
			int k, i, x; cin >> k >> i >> x;
			roots[k] = update(roots[k], x, i);
		} else if (t == 2) {
			int k, l, r; cin >> k >> l >> r;
			cout << query(roots[k], l, r) << '\n';
		} else {
			int k; cin >> k;
			roots[cnt++] = new Node(roots[k]);
		}
	}
	free(mem_pool);
}
