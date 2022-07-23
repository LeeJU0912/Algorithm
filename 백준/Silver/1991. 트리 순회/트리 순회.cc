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

int tree[26][2];

void preorder(char start) {
    if (start == '.') return;

    cout << start;
    preorder(tree[start - 'A'][0]);
    preorder(tree[start - 'A'][1]);

    return;
}

void inorder(char start) {
    if (start == '.') return;

    inorder(tree[start - 'A'][0]);
    cout << start;
    inorder(tree[start - 'A'][1]);

    return;
}

void postorder(char start) {
    if (start == '.') return;

    postorder(tree[start - 'A'][0]);
    postorder(tree[start - 'A'][1]);
    cout << start;

    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x;
    char a, b, c;

    cin >> x;

    for (int i = 0; i < x; i++) {
        cin >> a >> b >> c;
        tree[a - 'A'][0] = b;
        tree[a - 'A'][1] = c;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

    return 0;
}