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
#include <climits>
#include <cstdlib>
#include <utility>
#include <regex>
#include <numeric>

using namespace std;

int tree[10000];

void postorder(int start, int end) {
    if (start >= end) return;
    if (start == end - 1) {
        cout << tree[start] << '\n';
        return;
    }
    int temp = start + 1;
    while (temp < end) {
        if (tree[start] < tree[temp]) {
            break;
        }
        temp++;
    }
    postorder(start + 1, temp);
    postorder(temp, end);
    cout << tree[start] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int num;
    int idx = 0;
    while(cin >> num) {
        tree[idx++] = num;
    }

    postorder(0, idx);

    return 0;
}