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
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

int N, M;
int board[100][100];
int visited[100][100];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> NQ;

void First_Air_State() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while(!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now_x + dx[i];
            int next_y = now_y + dy[i];

            if (next_x >= N || next_x < 0 || next_y >= M || next_y < 0) continue;
            if (board[next_x][next_y] != 0) continue;

            if (visited[next_x][next_y] == 0) {
                visited[next_x][next_y] = 1;
                q.push({next_x, next_y});
            }
        }
    }
}

void Divide_Air() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 1) {
                for (int k = 0; k < 4; k++) {
                    int next_x = i + dx[k];
                    int next_y = j + dy[k];

                    if (next_x >= N || next_x < 0 || next_y >= M || next_y < 0) continue;
                    if (board[next_x][next_y] == 1) {
                        NQ.push({i, j});
                        break;
                    }
                }
            }
        }
    }
}

bool all_zero() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) return false;
        }
    }
    return true;
}

void Melt_Cheese() {
    queue<pair<int, int>> q = NQ; // 다음 큐를 옮겨 놓고 다음 큐 비우고 다시 갱신한다는 아이디어
    while(!NQ.empty()) NQ.pop();

    while(!q.empty()) {
        int now_x_cheese = q.front().first;
        int now_y_cheese = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x_cheese = now_x_cheese + dx[i];
            int next_y_cheese = now_y_cheese + dy[i];

            if (next_x_cheese >= N || next_x_cheese < 0 || next_y_cheese >= M || next_y_cheese < 0) continue;
            if (board[next_x_cheese][next_y_cheese] == 1) {
                board[next_x_cheese][next_y_cheese] = 0;
                NQ.push({next_x_cheese, next_y_cheese});
            }
        }
    }
}

void Add_Air() {
    queue<pair<int, int>> q = NQ;
    while (!q.empty()) {
        int now_x_air = q.front().first;
        int now_y_air = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x_air = now_x_air + dx[i];
            int next_y_air = now_y_air + dy[i];

            if (next_x_air >= N || next_x_air < 0 || next_y_air >= M || next_y_air < 0) continue;
            if (visited[next_x_air][next_y_air] == 0) {
                visited[next_x_air][next_y_air] = 1;
                q.push({next_x_air, next_y_air});
                NQ.push({next_x_air, next_y_air});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                visited[i][j] = -1; // 안쪽 공기 갱신할 때 안쪽 치즈까지 포함시키지 않기 위하여 입력.
            }
        }
    }

    First_Air_State();
    Divide_Air();

    int Time = 0;
    int Final_Size = 0;

    while(true) {
        if (all_zero()) break;
        Melt_Cheese(); // 새롭게 녹일 치즈 NQ에 저장
        Final_Size = NQ.size();

        Add_Air(); // 치즈에 구멍 뚫리면 새로 갱신하기
        Time++;
    }

    cout << Time << '\n';
    cout << Final_Size;

    return 0;
}