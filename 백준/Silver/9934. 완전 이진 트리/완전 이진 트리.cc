#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int K;
vector<vector<int>> tree;
vector<int> save;

int idx = 0;

void search(int depth) {
    if (depth == K) {
        tree[depth].push_back(save[idx++]);
        return;
    }

    search(depth + 1);
    tree[depth].push_back(save[idx++]);
    search(depth + 1);
}

int main() {
    FastIO

    cin >> K;
    tree = vector<vector<int>>(11, vector<int>());
    save = vector<int>(pow(2, K) - 1);
    for (int i = 0; i < pow(2, K) - 1; i++) {
        cin >> save[i];
    }

    search(1);

    for (int i = 1; i <= K; i++) {
        for (auto x : tree[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}