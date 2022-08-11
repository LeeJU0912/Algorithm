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

using namespace std;

int N;
int board[100001];
int cursor1, cursor2;
int ans = INT_MAX;
int ans1, ans2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    sort(board, board + N);

    cursor2 = N - 1;

    while (cursor1 < cursor2) {
        int sum = board[cursor1] + board[cursor2];
        if (abs(sum) < abs(ans)) {
            ans = sum;
            ans1 = board[cursor1];
            ans2 = board[cursor2];
            if (ans == 0) break;
        }
        if (sum < 0) {
            cursor1++;
        }
        else if (sum > 0) {
            cursor2--;
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}