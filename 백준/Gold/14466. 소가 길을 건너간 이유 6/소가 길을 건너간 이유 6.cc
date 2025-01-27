#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K, R;

bool isCow[101][101];
bool hasRoad[101][101][4];
bool visited[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vector<pair<int, int>> cows;

int groupCnt;
int group[101];
int hap[101];

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        if (isCow[nowX][nowY]) group[groupCnt]++;

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (nextX <= 0 || nextX > N || nextY <= 0 || nextY > N) continue;
            if (hasRoad[nowX][nowY][i]) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nextX, nextY});
        }
    }
}

int main() {
    FastIO

    cin >> N >> K >> R;

    for (int i = 0; i < R; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a == c) {
            if (b < d) {
                hasRoad[a][b][2] = true;
                hasRoad[c][d][3] = true;
            }
            else {
                hasRoad[a][b][3] = true;
                hasRoad[c][d][2] = true;
            }
        }
        else if (b == d) {
            if (a < c) {
                hasRoad[a][b][0] = true;
                hasRoad[c][d][1] = true;
            }
            else {
                hasRoad[a][b][1] = true;
                hasRoad[c][d][0] = true;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;

        isCow[a][b] = true;
        cows.push_back({a, b});
    }

    for (auto cow : cows) {
        if (visited[cow.first][cow.second]) continue;
        visited[cow.first][cow.second] = true;
        groupCnt++;
        bfs(cow.first, cow.second);
    }

    int ans = 0;
    for (int i = 1; i < groupCnt; i++) {
        hap[i] = hap[i - 1] + group[i];
        ans += hap[i] * group[i + 1];
    }

    cout << ans;

    return 0;
}