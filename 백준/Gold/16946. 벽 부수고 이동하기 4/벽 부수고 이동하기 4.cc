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
int board[1001][1001];
int visited[1001][1001];
int area_num[1001][1001];
int answer[1001][1001];
int zero_area_num;
vector<int> zero_area_size;

vector<pair<int, int>> one;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    int counter = 1;
    q.push({x, y});

    area_num[x][y] = zero_area_num;
    visited[x][y] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
            if (board[next_x][next_y] != 0) continue;

            if (!visited[next_x][next_y]) {
                visited[next_x][next_y] = 1;
                area_num[next_x][next_y] = zero_area_num;
                q.push({next_x, next_y});
                counter++;
            }
        }
    }
    zero_area_size.push_back(counter);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            board[i][j] = temp[j] - '0';
        }
    }

    memset(area_num, -1, sizeof(area_num));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 0 && visited[i][j] == 0) {
                bfs(i, j);
                zero_area_num++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1) {
                set<int> search;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
                    if (board[nx][ny] != 0) continue;

                    if (search.find(area_num[nx][ny]) == search.end()) {
                        search.insert(area_num[nx][ny]);
                        answer[i][j] += zero_area_size[area_num[nx][ny]];
                    }
                }
                answer[i][j] = answer[i][j] + 1;
                answer[i][j] = answer[i][j] % 10;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << answer[i][j];
        }
        cout << '\n';
    }

    return 0;
}