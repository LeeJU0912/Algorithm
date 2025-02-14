#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int H, W;
int board[1000][1000];
int cnt[1000][1000];
bool visited[1000][1000];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int ans;

vector<pair<int, int>> toCalc;

void solve() {
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < toCalc.size(); i++) {
        q.push({1, toCalc[i]});
        visited[toCalc[i].first][toCalc[i].second] = true;
    }

    while(!q.empty()) {
        int nowCnt = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        q.pop();

        ans = max(ans, nowCnt);

        for (int i = 0; i < 8; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            cnt[nextX][nextY]--;
            if (cnt[nextX][nextY] > 0) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nowCnt + 1, {nextX, nextY}});
        }
    }
}

int main() {
    FastIO

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < W; j++) {
            if (s[j] == '.') {
                visited[i][j] = true;
                continue;
            }
            board[i][j] = s[j] - '0';
        }
    }
    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            if (visited[i][j]) continue;

            int zero = 0;
            for (int k = 0; k < 8; k++) {
                int nextX = i + dx[k];
                int nextY = j + dy[k];
                if (board[nextX][nextY] == 0) zero++;
            }

            cnt[i][j] = board[i][j] - zero;

            if (cnt[i][j] <= 0) {
                toCalc.push_back({i, j});
            }
        }
    }

    solve();

    cout << ans;

    return 0;
}