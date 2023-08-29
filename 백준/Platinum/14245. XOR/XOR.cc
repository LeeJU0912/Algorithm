#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;
vector<int> tree;
vector<int> lazy;

void propagate(int node, int left, int right) {
	if (lazy[node] == 0) return;
	
	if (left != right) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	if ((right - left + 1) % 2 == 1) {
		tree[node] ^= lazy[node];
	}
	lazy[node] = 0;
}

void init(int node, int left, int right) {
	if (left == right) {
		tree[node] = save[left];
		return;
	}
	
	init(node * 2, left, (left + right) / 2);
	init(node * 2 + 1, (left + right) / 2 + 1, right);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int left, int right, int start, int end, int val) {
	propagate(node, left, right);
	
	if (left > end || right < start) return;
	if (start <= left && right <= end) {
		lazy[node] ^= val;
		
		propagate(node, left, right);
		return;
	}
	
	update(node * 2, left, (left + right) / 2, start, end, val);
	update(node * 2 + 1, (left + right) / 2 + 1, right, start, end, val);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1]; 
}

int query(int node, int left, int right, int idx) {
	propagate(node, left, right);
	
	if (right < idx || left > idx) return 0;
	if (left == right) {
		return tree[node];
	}
	
	int L = query(node * 2, left, (left + right) / 2, idx);
	int R = query(node * 2 + 1, (left + right) / 2 + 1, right, idx);
	
	return L + R;
}

int main() {
	FastIO
	
	cin >> N;
	int tree_depth = (int)ceil(log2(N));
	int tree_size = (1 << (tree_depth + 1));
	tree = vector<int>(tree_size);
	lazy = vector<int>(tree_size);
	save = vector<int>(N);
	
	for (int i = 0; i < N; i++) {
		cin >> save[i];
	}
	
	init(1, 0, N - 1);
	
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int order;
		cin >> order;
		
		if (order == 1) {
			int a, b, c;
			cin >> a >> b >> c;
			
			update(1, 0, N - 1, a, b, c);
		}
		else {
			int a;
			cin >> a;
			
			cout << query(1, 0, N - 1, a) << '\n';
		}
	}
	
	return 0;
}