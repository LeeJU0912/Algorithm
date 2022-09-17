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
#include <cctype>
#include <iomanip>
#include <bitset>

using namespace std;

int N;
long long ans;

long long getMax(vector<vector<long long>> board) {
    long long temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp = max(temp, board[i][j]);
        }
    }
    return temp;
}

vector<vector<long long>> right(vector<vector<long long>> board) {
    vector<vector<bool>> check(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            if (board[i][j] == 0) continue;

            for (int k = j + 1; k < N; k++) {
                if (board[i][k] == board[i][k - 1] && !check[i][k]) {
                    board[i][k] *= 2;
                    board[i][k - 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0) {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

vector<vector<long long>> left(vector<vector<long long>> board) {
    vector<vector<bool>> check(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (board[i][j] == 0) continue;

            for (int k = j - 1; k >= 0; k--) {
                if (board[i][k] == board[i][k + 1] && !check[i][k]) {
                    board[i][k] *= 2;
                    board[i][k + 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0) {
                    board[i][k] = board[i][k + 1];
                    board[i][k + 1] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

vector<vector<long long>> up(vector<vector<long long>> board) {
    vector<vector<bool>> check(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (board[j][i] == 0) continue;

            for (int k = j - 1; k >= 0; k--) {
                if (board[k][i] == board[k + 1][i] && !check[k][i]) {
                    board[k][i] *= 2;
                    board[k + 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0) {
                    board[k][i] = board[k + 1][i];
                    board[k + 1][i] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

vector<vector<long long>> down(vector<vector<long long>> board) {
    vector<vector<bool>> check(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            if (board[j][i] == 0) continue;

            for (int k = j + 1; k < N; k++) {
                if (board[k][i] == board[k - 1][i] && !check[k][i]) {
                    board[k][i] *= 2;
                    board[k - 1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0) {
                    board[k][i] = board[k - 1][i];
                    board[k - 1][i] = 0;
                }
                else {
                    break;
                }
            }
        }
    }
    return board;
}

void dfs(int counter, vector<vector<long long>> board) {
    ans = max(ans, getMax(board));

    if (counter == 5) return;
    dfs(counter + 1, right(board));
    dfs(counter + 1, left(board));
    dfs(counter + 1, up(board));
    dfs(counter + 1, down(board));

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    vector<vector<long long>> board(N, vector<long long>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, board);

    cout << ans;

    return 0;
}