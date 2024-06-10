#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;
vector<int> tree;

void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = save[start];
        return;
    }

    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);

    tree[node] = tree[node * 2] | tree[node * 2 + 1];
}

int query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return 0;
    if (start <= left && right <= end) return tree[node];

    int l = query(node * 2, left, (left + right) / 2, start, end);
    int r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return l | r;
}

int main() {
    FastIO

    cin >> N >> K;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<int>(tree_size);

    save = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    init(1, 0, N - 1);

    for (int i = 0; i < N; i++) {
        int start = i;
        int end = N - 1;

        int calc = 0;

        while(start <= end) {
            int mid = (start + end) / 2;

            if (query(1, 0, N - 1, i, mid) > K) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
                calc = mid;
            }
        }

        if (query(1, 0, N - 1, i, calc) == K) {
            cout << i + 1 << ' ' << calc + 1;
            return 0;
        }
    }

    cout << -1;

    return 0;
}