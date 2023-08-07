#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int A[500001];
int B[1000001];
vector<long long> tree;

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
    if (start <= left && right <= end) return tree[node];

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l + r;
}

int main() {
    FastIO

    cin >> N;

    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));

    tree = vector<long long>(tree_size);

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A[i] = temp;
    }
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        B[temp] = i;
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        ans += query(1, 0, N - 1, B[A[i]], N - 1);
        update(1, 0, N - 1, B[A[i]], 1);
    }

    cout << ans;

    return 0;
}