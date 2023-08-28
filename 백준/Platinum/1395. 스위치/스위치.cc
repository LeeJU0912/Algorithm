#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
vector<long long> tree;
vector<long long> lazy;

void propagate(int node, int left, int right) {
	if (lazy[node] == 0) return;
	
	if (left != right) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
		
		tree[node] = (right - left + 1) - tree[node];
	}
	else {
		tree[node] ^= lazy[node];
	}
	
	lazy[node] = 0;
}

void update(int node, int left, int right, int start, int end, long long val) {
	propagate(node, left, right);
	
	if (right < start || left > end) return;
	if (start <= left && right <= end) {
		lazy[node] ^= val;
		propagate(node, left, right);
		return;
	}
	
	update(node * 2, left, (left + right) / 2, start, end, val);
	update(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int start, int end) {
	propagate(node, left, right);
	
	if (right < start || left > end) return 0;
	if (start <= left && right <= end) return tree[node];
	
	long long L = query(node * 2, left, (left + right) / 2, start, end);
	long long R = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);
	
	return L + R;
}

int main() {
	FastIO
	
	cin >> N >> M;
	int tree_depth = (int)ceil(log2(N));
	int tree_size = (1 << (tree_depth + 1));
	tree = vector<long long>(tree_size);
	lazy = vector<long long>(tree_size);
	
	for (int i = 0; i < M; i++) {
		int order;
		cin >> order;
		
		if (order == 0) {
			int a, b;
			cin >> a >> b;
			update(1, 0, N - 1, a - 1, b - 1, 1);
		}
		else {
			int a, b;
			cin >> a >> b;
			cout << query(1, 0, N - 1, a - 1, b - 1) << '\n';
		}
	}
	
	return 0;
}