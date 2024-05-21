#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
vector<int> preorder, inorder, postorder;

vector<int> tree[1001];

void make_tree(int parent, int pre_idx, int start, int end) {
    if (pre_idx == n) return;
    if (start == n || end < 0) return;
    for (int i = start; i <= end; i++) {
        if (inorder[i] == preorder[pre_idx]) {
            make_tree(inorder[i], pre_idx + 1, start, i - 1);
            make_tree(inorder[i], pre_idx + 1, i + 1, end);
            tree[parent].push_back(inorder[i]);
            return;
        }
    }
    make_tree(parent, pre_idx + 1, start, end);
}

void get_postorder(int now) {
    for (int i = 0; i < tree[now].size(); i++) {
        get_postorder(tree[now][i]);
    }

    postorder.push_back(now);
}

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        preorder.clear();
        inorder.clear();
        postorder.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            preorder.push_back(temp);

            tree[i + 1].clear();
        }
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            inorder.push_back(temp);
        }

        for (int i = 0; i < n; i++) {
            if (inorder[i] == preorder[0]) {
                make_tree(preorder[0], 1, 0, i - 1);
                make_tree(preorder[0], 1, i + 1, n - 1);
                break;
            }
        }

        get_postorder(preorder[0]);

        for (int i = 0; i < postorder.size(); i++) {
            cout << postorder[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}