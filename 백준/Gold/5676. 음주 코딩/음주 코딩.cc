#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> tree;
vector<int> save;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = save[left];
        return;
    }
    else {
        init(node * 2, left, (left + right) / 2);
        init(node * 2 + 1, (left + right) / 2 + 1, right);
        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
}

void update(int node, int left, int right, int target, int val) {
    if (left > target || right < target) return;
    if (left == right) {
        if (val > 0) {
            save[target] = 1;
            tree[node] = 1;
        }
        else if (val < 0) {
            save[target] = -1;
            tree[node] = -1;
        }
        else {
            save[target] = 0;
            tree[node] = 0;
        }

        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = tree[node * 2] * tree[node * 2 + 1];
}

int query(int node, int left, int right, int start, int end) {
    if (left > end || right < start) return 1;
    if (left >= start && right <= end) return tree[node];

    return query(node * 2, left, (left + right) / 2, start, end) * query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);
}

int main() {
    FastIO

    while(cin >> N >> K) {
        int tree_depth = (int)ceil(log2(N));
        int tree_size = (1 << (tree_depth + 1));

        tree = vector<int>(tree_size);

        save.clear();

        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;

            if (temp > 0) {
                temp = 1;
            }
            else if (temp < 0) {
                temp = -1;
            }
            else {
                temp = 0;
            }

            save.push_back(temp);
        }

        init(1, 0, N - 1);

        for (int i = 0; i < K; i++) {
            char a;
            int b, c;
            cin >> a >> b >> c;

            if (a == 'C') {
                update(1, 0, N - 1, b - 1, c);
            }
            else if (a == 'P') {
                int result = query(1, 0, N - 1, b - 1, c - 1);
                if (result > 0) {
                    cout << '+';
                }
                else if (result < 0) {
                    cout << '-';
                }
                else {
                    cout << 0;
                }
            }
        }

        cout << '\n';
    }

    return 0;
}