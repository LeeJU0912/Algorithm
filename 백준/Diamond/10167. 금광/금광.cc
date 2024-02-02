#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct Node {
    long long all_sum;
    long long left_sum;
    long long right_sum;
    long long max_sum;
};

Node merge(Node a, Node b) {
    Node X;
    X.all_sum = a.all_sum + b.all_sum;
    X.left_sum = max(a.left_sum, a.all_sum + b.left_sum);
    X.right_sum = max(b.right_sum, b.all_sum + a.right_sum);
    X.max_sum = max(max(a.max_sum, b.max_sum), a.right_sum + b.left_sum);

    return X;
}

int N;
vector<pair<pair<int, int>, long long>> save;

long long compressed[3001][3001];

vector<Node> tree;

set<int> X, Y;
map<int, int> CX, CY;

int up, down;

void update(int node, int left, int right) {
    if (left == right) {
        tree[node] = {compressed[left][up] - compressed[left][down - 1], compressed[left][up] - compressed[left][down - 1], compressed[left][up] - compressed[left][down - 1], compressed[left][up] - compressed[left][down - 1]};
        return;
    }

    update(node * 2, left, (left + right) / 2);
    update(node * 2 + 1, (left + right) / 2 + 1, right);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

Node query(int node, int left, int right, int start, int end) {
    if (start > right || left > end) return {-(1 << 16), -(1 << 16), -(1 << 16), -(1 << 16)};
    if (left <= start || end <= right) return tree[node];

    Node L = query(node * 2, left, (left + right) / 2, start, end);
    Node R = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    return merge(L, R);
}

int main() {
    FastIO

    cin >> N;
    int tree_depth = (int)ceil(log2(N));
    int tree_size = (1 << (tree_depth + 1));
    tree = vector<Node>(tree_size);

    for (int i = 0; i < N; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        save.push_back({{x, y}, w});
        X.insert(x);
        Y.insert(y);
    }

    int counter = 1;
    for (int z : X) {
        CX[z] = counter++;
    }

    counter = 1;
    for (int z : Y) {
        CY[z] = counter++;
    }

    int a = X.size();
    int b = Y.size();

    for (int i = 0; i < N; i++) {
        compressed[CX[save[i].first.first]][CY[save[i].first.second]] = save[i].second;
    }

    for (int i = 2; i <= b; i++) {
        for (int j = 1; j <= a; j++) {
            compressed[j][i] += compressed[j][i - 1];
        }
    }

    long long ans = LLONG_MIN;

    // y의 범위 설정
    for (down = 1; down <= b; down++) {
        tree = vector<Node>(tree_size);
        for (up = down; up <= b; up++) {
            update(1, 1, N);
            // x축을 따라 전체 구간에서 가장 최댓값 구하기
            ans = max(ans, query(1, 1, a, 1, a).max_sum);
        }
    }

    cout << ans;

    return 0;
}