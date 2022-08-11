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

int N, S;
int board[100001];
int sum;
int cursor1, cursor2;
int ans = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> board[i];
    }
    cursor1 = 1;
    cursor2 = 1;

    while(cursor1 <= cursor2) {
        if (sum >= S) { // 구간합이 목표치보다 클 때
            ans = min(ans, cursor2 - cursor1); // 정답! 최소값(기존값, 지금 구간 너비)
            sum -= board[cursor1]; // 왼쪽 커서 당겨서 합계치 줄여나간다.
            cursor1++;
        }
        else if (cursor2 == N + 1) break; // 커서가 마지막에 닿으면 정지
        else { // 구간합이 목표치보다 작을 때
            sum += board[cursor2]; // 계속해서 오른쪽으로 합계치 경신해 나간다.
            cursor2++;
        }
    }

    if (ans == INT_MAX) {
        cout << 0;
    }
    else {
        cout << ans;
    }

    return 0;
}