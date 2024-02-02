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
    c.max_sum = max({c.all_sum, a.right_sum + b.left_sum, a.max_sum, b.max_sum});

    return c;
}

int N;
vector<pair<pair<int, int>, int>> save;
set<int> X, Y;
map<int, int> conv_x, conv_y;

vector<Node> tree;

bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
    return a.first.second < b.first.second;
}

void update(int node, int left, int right, int target, int val) {
    if (right < target || left > target) return;
    if (left == right) {
        tree[node].all_sum += val;
        tree[node].left_sum += val;
        tree[node].right_sum += val;
        tree[node].max_sum += val;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int main() {
    FastIO

    cin >> N;

    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));

    for (int i = 0; i < N; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        save.push_back({{x, y}, w});
        X.insert(x);
        Y.insert(y);
    }

    int counter = 1;
    for (int x : X) {
        conv_x[x] = counter++;
    }

    counter = 1;
    for (int y : Y) {
        conv_y[y] = counter++;
    }

    for (int i = 0; i < N; i++) {
        save[i].first.first = conv_x[save[i].first.first];
        save[i].first.second = conv_y[save[i].first.second];
    }

    sort(save.begin(), save.end(), comp);

    long long ans = 0;
    for (int y = 1; y <= Y.size(); y++) {
        tree = vector<Node>(tree_size);

        for (int j = 0; j < N; j++) {
            if (save[j].first.second < y) continue;
            update(1, 1, N, save[j].first.first, save[j].second);

            if (j == N - 1 || save[j].first.second != save[j + 1].first.second) {
                ans = max(ans, tree[1].max_sum);
            }
        }
    }

    cout << ans;

    return 0;
}