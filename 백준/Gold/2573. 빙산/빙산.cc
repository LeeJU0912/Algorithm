#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[301][301];
int toDecrease[301][301];
bool visited[301][301];
vector<pair<int, int>> meltList;

int year;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void makeDecrease(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
        if (board[next_x][next_y] == 0) toDecrease[x][y]++;
    }
}

void melt() {
    map<pair<int, int>, int> decreasePlus;
    vector<pair<int, int>> nextMeltList;

    for (int i = 0; i < meltList.size(); i++) {
        int now_x = meltList[i].first;
        int now_y = meltList[i].second;

        board[now_x][now_y] = max(board[now_x][now_y] - toDecrease[now_x][now_y], 0);

        if (board[now_x][now_y] == 0) {
            for (int j = 0; j < 4; j++) {
                int next_x = now_x + dx[j];
                int next_y = now_y + dy[j];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
                decreasePlus[{next_x, next_y}]++;
            }
        }
        else {
            nextMeltList.push_back({now_x, now_y});
        }
    }

    meltList = nextMeltList;

    for (auto i : decreasePlus) {
        int now_x = i.first.first;
        int now_y = i.first.second;

        toDecrease[now_x][now_y] += i.second;
    }
}

int chk() {
    memset(visited, false, sizeof(visited));

    int counter = 0;

    for (int i = 0; i < meltList.size(); i++) {
        int melt_x = meltList[i].first;
        int melt_y = meltList[i].second;

        if (visited[melt_x][melt_y]) continue;

        counter++;

        queue<pair<int, int>> q;
        q.push({melt_x, melt_y});
        visited[melt_x][melt_y] = true;

        while(!q.empty()) {
            int now_x = q.front().first;
            int now_y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int next_x = now_x + dx[k];
                int next_y = now_y + dy[k];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M) continue;
                if (board[next_x][next_y] == 0) continue;
                if (visited[next_x][next_y]) continue;
                visited[next_x][next_y] = true;

                q.push({next_x, next_y});
            }
        }
    }
    
    return counter;
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                meltList.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            makeDecrease(i, j);
        }
    }

    while(meltList.size() && chk() == 1) {
        melt();
        year++;
    }

    cout << (meltList.size() == 0 ? 0 : year);

    return 0;
}