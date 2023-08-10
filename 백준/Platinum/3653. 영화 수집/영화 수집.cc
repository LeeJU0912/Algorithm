#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;
vector<long long> tree;

void init(int node, int left, int right) {
    if (right < M) return;
    if (left == right) {
        tree[node] = 1;
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int left, int right, int target, long long val) {
    if (target < left || target > right) return;

    if (left == right) {
        tree[node] = val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int start, int end) {
    if (left > end || right < start) return 0;
    if (left >= start && right <= end) return tree[node];

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        cin >> N >> M;

        int tree_depth = (int)ceil(log2(N + M));
        int tree_size = (1 << (tree_depth + 1));
        tree = vector<long long>(tree_size);

        save = vector<int>(N + 1);

        for (int i = 1; i <= N; i++) {
            save[i] = M + i - 1;
        }

        init(1, 0, M + N - 1);


        for (int i = M - 1; i >= 0; i--) {
            int movie;
            cin >> movie;

            cout << query(1, 0, N + M - 1, 0,save[movie]) - 1 << ' ';

            update(1, 0, N + M - 1, i, 1);
            update(1, 0, N + M - 1, save[movie], 0);

            save[movie] = i;
        }
        cout << '\n';
    }

    return 0;
}