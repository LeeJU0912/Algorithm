#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
char board[51][51];
int depth[51][51];
bool visited[51][51];

pair<int, int> start;
vector<pair<int, int>> house;
vector<int> height;

int limit_maxi;
int limit_mini;

int ans = INT_MAX;

int dx[8] = {0, 1, 1, 1, 0, -1, - 1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

void go() {
    if (depth[start.first][start.second] < height[limit_mini] || depth[start.first][start.second] > height[limit_maxi]) return;

    queue<pair<int, int>> q;
    q.push(start);

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int next_x = now.first + dx[i];
            int next_y = now.second + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if (depth[next_x][next_y] > height[limit_maxi] || depth[next_x][next_y] < height[limit_mini]) continue;

            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            q.push({next_x, next_y});
        }
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'P') {
                start.first = i;
                start.second = j;
            }
            else if (board[i][j] == 'K') {
                house.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> depth[i][j];
            height.push_back(depth[i][j]);
        }
    }

    sort(height.begin(), height.end());

    while(limit_maxi < height.size() && limit_mini < height.size()) {
        memset(visited, false, sizeof(visited));

        go();

        int house_chk = 0;
        for (int i = 0; i < house.size(); i++) {
            if (visited[house[i].first][house[i].second]) house_chk++;
        }

        if (house_chk == house.size()) {
            ans = min(ans, height[limit_maxi] - height[limit_mini]);
            limit_mini++;
        }
        else limit_maxi++;
    }
    
    cout << ans;

    return 0;
}