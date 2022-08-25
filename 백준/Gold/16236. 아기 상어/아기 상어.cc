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

using namespace std;

int N;
int space[21][21];
int fish;
int start_i;
int start_j;
int shark = 2;
int ans;
int dist = 10000000;
int temp_i;
int temp_j;
int counter;
bool visited[21][21];

int x[4] = {1, -1, 0, 0};
int y[4] = { 0, 0, 1, -1};

int bfs(int i, int j) {
    queue<tuple<int, int, int>> q;

    q.push(make_tuple(start_i, start_j, 0));
    visited[start_i][start_j] = true;

    while(!q.empty()) {
        int cur_i = get<0>(q.front());
        int cur_j = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if (cur_i == i && cur_j == j) {
            return cnt;
        }

        for (int k = 0; k < 4; k++) {
            int next_i = cur_i + x[k];
            int next_j = cur_j + y[k];

            if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= N) {
                continue;
            }
            if (visited[next_i][next_j]) {
                continue;
            }
            if (space[next_i][next_j] <= shark) {
                q.push( make_tuple(next_i, next_j, cnt + 1));
                visited[next_i][next_j] = true;
            }
        }
    }
    return dist;
}

void solve() {
    if (!fish) {
        return;
    }
    if (fish == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (space[i][j] != 0 && space[i][j] != 9) {
                    ans = abs(i - start_i) + abs(j - start_j);
                    return;
                }
            }
        }
    }

    else {
        while (fish) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (space[i][j] != 0 && space[i][j] != 9 && space[i][j] < shark) {

                        int tmp = bfs(i, j);
                        memset(visited, 0, sizeof(visited));

                        if (dist > tmp) {
                            dist = tmp;
                            temp_i = i;
                            temp_j = j;
                        }
                    }
                }
            }
            if (dist == 10000000) { // for문에서 하나도 안 걸렸으면 (못 먹는 큰 물고기들 밖에 없으면)
                return;
            }

            ans += dist;
            space[start_i][start_j] = 0; // 원래 있던 자리 0으로 만들고 이동
            start_i = temp_i;
            start_j = temp_j;

            fish--;

            counter++;

            if (counter == shark) {
                shark++;
                counter = 0;
            }

            space[start_i][start_j] = 9;
            dist = 10000000;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> space[i][j];
            if (space[i][j] != 0 && space[i][j] != 9) {
                fish++;
            }
            else if (space[i][j] == 9) {
                start_i = i;
                start_j = j;
            }
        }
    }

    solve();

    cout << ans;

    return 0;
}