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

int R, C;
char board[21][21];
int visited[26];

int answer = 0;

void solve (int x, int y, int counter) {
    if (answer < counter) answer = counter;
    if (x == -1 || y == -1 || x == R || y == C) return;
    if (visited[board[x][y] - 'A']) return;
    visited[board[x][y] - 'A'] = 1;

    solve(x + 1, y, counter + 1);
    solve(x - 1, y, counter + 1);
    solve(x, y + 1, counter + 1);
    solve(x, y - 1, counter + 1);

    visited[board[x][y] - 'A'] = 0;

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            board[i][j] = s[j];
        }
    }

    solve(0, 0, 0);

    cout << answer;

    return 0;
}