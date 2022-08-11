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

using namespace std;

int N;
long long board[5001];
long long cursor1, cursor2;
long long ans = 3000000001;
long long ans1, ans2, ans3;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    sort(board, board + N);

    for (int i = 0; i < N - 2; i++) {
        cursor1 = i + 1;
        cursor2 = N - 1;
        while (cursor1 < cursor2) {
            long long sum = board[i] + board[cursor1] + board[cursor2];
            if (abs(sum) < ans) {
                ans = abs(sum);
                ans1 = board[i];
                ans2 = board[cursor1];
                ans3 = board[cursor2];
            }

            if (sum < 0) {
                cursor1++;
            }
            else if (sum > 0) {
                cursor2--;
            }
            else {
                i = N;
                break;
            }
        }
    }

    cout << ans1 << ' ' << ans2 << ' ' << ans3;

    return 0;
}