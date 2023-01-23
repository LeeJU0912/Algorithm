#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long arr[1000000];
long long tree[1000000 * 4];

long long init_segtree(long long start, long long end, long long node) {
    if (start == end) return tree[node] = arr[start];

    long long mid = (start + end) / 2;

    return tree[node] = init_segtree(start, mid, node * 2)
            + init_segtree(mid + 1, end, node * 2 + 1);
}

void update_segtree(long long start, long long end, long long node, long long index, long long change) {
    if (index < start || end < index) return;
    tree[node] += change;
    if (start != end) {
        long long mid = (start + end) / 2;
        update_segtree(start, mid, node * 2, index, change);
        update_segtree(mid + 1, end, node * 2 + 1, index, change);
    }
    return;
}

long long sum_segtree(long long start, long long end, long long left, long long right, long long node) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return tree[node];
    else {
        long long mid = (start + end) / 2;
        return sum_segtree(start, mid, left, right, node * 2)
        + sum_segtree(mid + 1, end, left, right, node * 2 + 1);
    }
}

int main() {
    FastIO;
    int N, M, K;
    cin >> N >> M >> K;


    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    init_segtree(0, N - 1, 1);


    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            b--;
            update_segtree(0, N - 1, 1, b, c - arr[b]);
            arr[b] = c;
        }
        else {
            b--; c--;
            cout << sum_segtree(0, N - 1, b, c, 1) << '\n';
        }
    }

    return 0;
}