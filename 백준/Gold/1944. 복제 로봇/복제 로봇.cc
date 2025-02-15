#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[50][50];
int keyIdx[50][50];
bool visited[50][50];
int visitedGraph[251];
pair<int, int> start;
vector<pair<int, int>> keys;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> graph[251];

int ans;

void solve(int idx) {
    memset(visited, false, sizeof(visited));

    queue<pair<int, pair<int, int>>> q;
    q.push({0, keys[idx]});
    visited[keys[idx].first][keys[idx].second] = true;

    while(!q.empty()) {
        int nowCnt = q.front().first;
        int nowX = q.front().second.first;
        int nowY = q.front().second.second;
        q.pop();

        if (board[nowX][nowY] == 2) {
            graph[idx].push_back({nowCnt, keyIdx[nowX][nowY]});
        }

        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];

            if (board[nextX][nextY] == 1) continue;
            if (visited[nextX][nextY]) continue;
            visited[nextX][nextY] = true;

            q.push({nowCnt + 1, {nextX, nextY}});
        }
    }
}

void findShortest() {
    int cnt = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, M});

    while(!pq.empty()) {
        int nowDist = pq.top().first;
        int nowNode = pq.top().second;
        pq.pop();

        if (visitedGraph[nowNode]) continue;
        visitedGraph[nowNode] = true;
        cnt++;

        ans += nowDist;

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextDist = graph[nowNode][i].first;
            int nextNode = graph[nowNode][i].second;

            pq.push({nextDist, nextNode});
        }
    }

    if (cnt != M + 1) {
        ans = -1;
    }
}

int main() {
    FastIO

    int idx = 0;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            if (s[j] == '1') {
                board[i][j] = 1;
            }
            else if (s[j] == 'K') {
                board[i][j] = 2;
                keys.push_back({i, j});
                keyIdx[i][j] = idx++;
            }
            else if (s[j] == 'S') {
                start = {i, j};
            }
        }
    }

    keys.push_back(start);
    for (int i = 0; i <= M; i++) {
        board[keys[i].first][keys[i].second] = 0;
        solve(i);
        board[keys[i].first][keys[i].second] = 2;
    }

    findShortest();

    cout << ans;

    return 0;
}