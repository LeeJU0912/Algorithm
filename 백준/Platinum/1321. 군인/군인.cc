#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save;
vector<long long> tree;

void init(int node, int left, int right) {
    if (left > right) return;
    if (left == right) {
        tree[node] = save[left];
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update(int node, int left, int right, int target, long long val) {
    if (target > right || target < left) return;
    if (left == right) {
        tree[node] += val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int start, int end) {
    if (right < start || left > end) return 0;
    if (start <= left && right <= end) return tree[node];

    long long L = query(node * 2, left, (left + right) / 2, start, end);
    long long R = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return L + R;
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
        save.push_back(temp);
    }

    init(1, 0, N - 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        int order;
        cin >> order;

        if (order == 1) {
            int a, b;
            cin >> a >> b;
            update(1, 0, N - 1, a - 1, b);
        }
        else {
            long long a;
            cin >> a;

            int start = 0;
            int end = N - 1;
            int ans;

            while(start <= end) {
                int mid = (start + end) / 2;
                long long now = query(1, 0, N - 1, 0, mid);
                if (now < a) start = mid + 1;
                else {
                    ans = mid;
                    end = mid - 1;
                }
            }

            cout << ans + 1 << '\n';
        }
    }

    return 0;
}