#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<string, Node> child;
};

void insert(Node &p, vector<string> v, int idx) {
    if (idx == v.size()) return;

    if (!p.child.count(v[idx])) {
        p.child[v[idx]] = Node();
    }

    insert(p.child[v[idx]], v, idx + 1);
}

void print(Node &p, int depth = 0) {
    for (auto node : p.child) {
        for (int i = 0; i < depth; i++) {
            cout << "--";
        }
        cout << node.first << '\n';

        print(node.second, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    Node root;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        vector<string> v(K);

        for (int j = 0; j < K; j++) {
            cin >> v[j];
        }
        insert(root, v, 0);
    }

    print(root);

    return 0;
}