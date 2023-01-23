#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long arr[1000000];
pair<long long, long long> tree[1000000 * 4];

pair<long long, long long> init_segtree(long long start, long long end, long long node) {
    if (start == end) return tree[node] = {arr[start], arr[start]};

    long long mid = (start + end) / 2;

    auto a = init_segtree(start, mid, node * 2);
    auto b = init_segtree(mid + 1, end, node * 2 + 1);

    return tree[node] = {min(a.first, b.first), max(a.second, b.second)};
}
//
//void update_segtree(long long start, long long end, long long node, long long index, long long change) {
//    if (index < start || end < index) return;
//
//    if (start == end) {
//        tree[node] = change;
//        return;
//    }
//    if (start != end) {
//        long long mid = (start + end) / 2;
//        update_segtree(start, mid, node * 2, index, change);
//        update_segtree(mid + 1, end, node * 2 + 1, index, change);
//    }
//    tree[node] = tree[node * 2] * tree[node * 2 + 1] % 1000000007;
//}

pair<long long, long long> sum_segtree(long long start, long long end, long long left, long long right, long long node) {
    if (right < start || left > end) return {LLONG_MAX, LLONG_MIN};
    if (left <= start && end <= right) {
        return tree[node];
    }
    else {
        long long mid = (start + end) / 2;
        auto a = sum_segtree(start, mid, left, right, node * 2);
        auto b = sum_segtree(mid + 1, end, left, right, node * 2 + 1);
        return {min(a.first, b.first), max(a.second, b.second)};
    }
}

int main() {
    FastIO;
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init_segtree(1, N, 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        auto c = sum_segtree(1, N, a, b, 1);
        cout << c.first << ' ' << c.second << '\n';
    }

    return 0;
}