#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
long long board[101][101];
vector<pair<pair<int, int>, pair<int, int>>> roads;

int main() {
    FastIO

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        roads.push_back({{a, b}, {c, d}});
    }

    board[0][0] = 1;
    for (int i = 0; i <= min(N, M); i++) {
        for (int j = i + 1; j <= N; j++) {
            int now_y = i;
            int next_y = i + 1;
            int now_x = j - 1;
            int next_x = j;

            bool chk1 = false;
            bool chk2 = false;

            pair<int, int> p1 = {now_x, now_y};
            pair<int, int> p2 = {next_x, now_y};
            pair<int, int> p3 = {next_x, next_y};

            for (int k = 0; k < K; k++) {
                auto point1 = roads[k].first;
                auto point2 = roads[k].second;

                if ((point1 == p1 && point2 == p2) ||
                        (point1 == p2 && point2 == p1))
                    chk1 = true;
                if ((point1 == p2 && point2 == p3) ||
                    (point1 == p3 && point2 == p2))
                    chk2 = true;
            }

            if (!chk1) {
                board[next_x][now_y] += board[now_x][now_y];
            }

            if (next_y > M) continue;
            if (!chk2) {
                board[next_x][next_y] += board[next_x][now_y];
            }
        }
        for (int j = i + 1; j <= M; j++) {
            int now_x = i;
            int next_x = i + 1;
            int now_y = j - 1;
            int next_y = j;

            bool chk1 = false;
            bool chk2 = false;

            pair<int, int> p1 = {now_x, now_y};
            pair<int, int> p2 = {now_x, next_y};
            pair<int, int> p3 = {next_x, next_y};

            for (int k = 0; k < K; k++) {
                auto point1 = roads[k].first;
                auto point2 = roads[k].second;

                if ((point1 == p1 && point2 == p2) ||
                    (point1 == p2 && point2 == p1))
                    chk1 = true;
                if ((point1 == p2 && point2 == p3) ||
                    (point1 == p3 && point2 == p2))
                    chk2 = true;
            }

            if (!chk1) {
                board[now_x][next_y] += board[now_x][now_y];
            }

            if (next_x > N) continue;
            if (!chk2) {
                board[next_x][next_y] += board[now_x][next_y];
            }
        }
    }

    cout << board[N][M];

    return 0;
}