#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;
vector<int> tree;

void init(int node, int left, int right) {
    if (left > right) return;
    if (left == right) {
        tree[node] = save[left];
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return -1;
    if (start <= left && right <= end) return tree[node];

    int L = query(node * 2, left, (left + right) / 2, start, end);
    int R = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    if (L == -1) return R;
    if (R == -1) return L;
    if (L > R) return L;
    else return R;
}

int main() {
    FastIO

    cin >> N >> M;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    init(1, 0, N - 1);

    for (int i = M - 1; i < N - M + 1; i++) {
        cout << query(1, 0, N - 1, i - M + 1, i + M - 1) << ' ';
    }

    return 0;
}