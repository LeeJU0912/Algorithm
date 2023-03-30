#include <bits/stdc++.h>
using namespace std;

int N;
int board[126][126];
int dist[126][126];
int ans = INT_MAX;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dijkstra(int x, int y) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    dist[0][0] = board[0][0];
    pq.push({dist[0][0], {x, y}});

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = now.second.first + dx[i];
            int next_y = now.second.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;

            if (dist[next_x][next_y] > now.first + board[next_x][next_y]) {
                dist[next_x][next_y] = now.first + board[next_x][next_y];
                pq.push({dist[next_x][next_y], {next_x, next_y}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int counter = 0;

    while(true) {
        counter++;

        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
                dist[i][j] = INT_MAX;
            }
        }

        dijkstra(0, 0);

        cout << "Problem " << counter << ": " << dist[N - 1][N - 1] << '\n';
    }

    return 0;
}