#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int M;
vector<int> tree;
map<int, int> compressed;
map<int, int> compressed2;

void update(int node, int left, int right, int target) {
    if (left > target || right < target) return;
    if (left == right) {
        tree[node]++;
        return;
    }

    update(node * 2, left, (left + right) / 2, target);
    update(node * 2 + 1, (left + right) / 2 + 1, right, target);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int left, int right, int nth) {
    if (left == right) return compressed[right];

    if (tree[node * 2] >= nth) {
        return query(node * 2, left, (left + right) / 2, nth);
    }
    else {
        return query(node * 2 + 1, (left + right) / 2 + 1, right, nth - tree[node * 2]);
    }
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        compressed.clear();
        compressed2.clear();

        cin >> M;
        vector<int> save(M);

        int tree_height = (int)ceil(log2(M));
        int tree_size = (1 << (tree_height + 1));
        tree = vector<int>(tree_size);

        for (int i = 0; i < M; i++) {
            cin >> save[i];
        }

        vector<int> sorted = save;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < M; i++) {
            compressed.insert({i, sorted[i]});
            compressed2.insert({sorted[i], i});
        }



        vector<int> ans;
        for (int i = 0; i < M; i++) {
            update(1, 0, M - 1, compressed2[save[i]]);

            if (i % 2 == 0) {
                ans.push_back(query(1, 0, M - 1, i / 2 + 1));
            }
        }


        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
            if (i % 10 == 9) cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}