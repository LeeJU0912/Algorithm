#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct Node {
    long long all_sum;
    long long left_sum;
    long long right_sum;
    long long max_sum;
};

Node merge(Node a, Node b) {
    Node c;
    c.all_sum = a.all_sum + b.all_sum;
    c.left_sum = max(a.left_sum, a.all_sum + b.left_sum);
    c.right_sum = max(b.right_sum, a.right_sum + b.all_sum);
    c.max_sum = max(max(a.max_sum, b.max_sum), a.right_sum + b.left_sum);

    return c;
}

int N, M;
vector<int> save;
vector<Node> tree;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node].all_sum = save[left];
        tree[node].left_sum = save[left];
        tree[node].right_sum = save[left];
        tree[node].max_sum = save[left];
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int left, int right, int start, int end) {
    if (right < start || end < left) return {0, (long long)-1e16, (long long)-1e16, (long long)-1e16};
    if (start <= left && right <= end) return tree[node];

    Node l = query(node * 2, left, (left + right) / 2, start, end);
    Node r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return merge(l, r);
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<Node>(tree_size);
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    init(1, 0, N - 1);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        Node l = query(1, 0, N - 1, x1 - 1, y1 - 1);
        Node r = query(1, 0, N - 1, x2 - 1, y2 - 1);

        // 완전히 겹칠 때
        if (x1 == x2 && y1 == y2) {
            cout << l.max_sum << '\n';
        }
        // 안 겹칠 때
        else if (y1 + 2 <= x2) {
            long long mid_all = query(1, 0, N - 1, y1, x2 - 2).all_sum;
            cout << l.right_sum + mid_all + r.left_sum << '\n';
        }
        else if (y1 + 1 == x2) {
            cout << l.right_sum + r.left_sum << '\n';
        }
        // 겹칠 때
        else {
            long long ans = LLONG_MIN;
            if (x1 == x2) {
                Node mid = query(1, 0, N - 1, x2 - 1, y1 - 1);
                Node r2 = query(1, 0, N - 1, y1, y2 - 1);
                
                ans = max(ans, mid.max_sum);
                ans = max(ans, mid.right_sum + r2.left_sum);
            }
            else if (y1 == y2) {
                Node l2 = query(1, 0, N - 1, x1 - 1, x2 - 2);
                Node mid = query(1, 0, N - 1, x2 - 1, y1 - 1);

                ans = max(ans, mid.max_sum);
                ans = max(ans, l2.right_sum + mid.left_sum);
            }
            else {
                Node l2 = query(1, 0, N - 1, x1 - 1, x2 - 2);
                Node mid = query(1, 0, N - 1, x2 - 1, y1 - 1);
                Node r2 = query(1, 0, N - 1, y1, y2 - 1);

                ans = l2.right_sum + mid.all_sum + r2.left_sum;
                ans = max(ans, mid.max_sum);
                ans = max(ans, l2.right_sum + mid.left_sum);
                ans = max(ans, mid.right_sum + r2.left_sum);
            }
            
            cout << ans << '\n';
        }
    }

    return 0;
}