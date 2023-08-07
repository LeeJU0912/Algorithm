#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
int M;

vector<long long> tree;

void update(int node, int left, int right, int target, long long val) {
    if (target < left || target > right) return;
    if (left == right) {
        save[target] = val;
        tree[node] = val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int start, int end) {
    if (left > end || right < start) return 0;
    if (start <= left && right <= end) return tree[node];

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    cin >> N >> M;

    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<long long>(tree_size);

    save = vector<int>(N);


    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0) {
            if (b > c) swap(b, c);
            cout << query(1, 0, N - 1, b - 1, c - 1) << '\n';
        }
        else {
            update(1, 0, N - 1, b - 1, c);
        }

    }

    return 0;
}