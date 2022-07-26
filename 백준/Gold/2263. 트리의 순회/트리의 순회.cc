#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>

using namespace std;

int inorder[100001];
int postorder[100001];
int idx[100001];

void preorder(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;

    int root_node = postorder[post_end];
    int left_cnt = idx[root_node] - in_start;

    cout << root_node << ' ';

    preorder(in_start, idx[root_node] - 1, post_start, post_start + left_cnt - 1);
    preorder(idx[root_node] + 1, in_end, post_start + left_cnt, post_end - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }
    for (int i = 0; i < N; i++) {
        idx[inorder[i]] = i;
    }

    preorder(0, N - 1, 0, N - 1);

    return 0;
}