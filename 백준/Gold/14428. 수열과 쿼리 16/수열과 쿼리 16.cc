#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
int M;

vector<long long> tree;

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = left;
        return;
    }

    init(node * 2, left, (left + right) / 2);
    init(node * 2 + 1, (left + right) / 2 + 1, right);

    if (save[tree[node * 2]] <= save[tree[node * 2 + 1]]) {
        tree[node] = tree[node * 2];
    }
    else tree[node] = tree[node * 2 + 1];
}

void update(int node, int left, int right, int target, long long val) {
    if (target < left || target > right) return;
    if (left == right) {
        save[target] = val;
        tree[node] = left;
        return;
    }

    update(node * 2, left, (left + right) / 2, target, val);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target, val);

    if (save[tree[node * 2]] <= save[tree[node * 2 + 1]]) {
        tree[node] = tree[node * 2];
    }
    else tree[node] = tree[node * 2 + 1];
}

long long query(int node, int left, int right, int start, int end) {
    if (left > end || right < start) return -1;
    if (start <= left && right <= end) return tree[node];

    long long l = query(node * 2, left, (left + right) / 2, start, end);
    long long r = query(node * 2 + 1, (left + right) / 2 + 1, right, start, end);

    if (l == -1) return r;
    if (r == -1) return l;
    if (save[l] <= save[r]) return l;
    else return r;
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

    cin >> M;

    init(1, 0, N - 1);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a;

        if (a == 1) {
            cin >> b >> c;
            update(1, 0, N - 1, b - 1, c);
        }
        else {
            cin >> b >> c;
            cout << query(1, 0, N - 1, b - 1, c - 1) + 1 << '\n';
        }
    }

    return 0;
}