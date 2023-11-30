#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
bool board[51][51];
bool visited[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

void solve() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    pq.push({0, {0, 0}});
    visited[0][0] = true;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (now.second.first == n - 1 && now.second.second == n - 1) {
            ans = now.first;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int next_x = now.second.first + dx[i];
            int next_y = now.second.second + dy[i];

            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) continue;
            if (visited[next_x][next_y]) continue;
            visited[next_x][next_y] = true;

            if (!board[next_x][next_y]) {
                pq.push({now.first + 1, {next_x, next_y}});
            }
            else {
                pq.push({now.first, {next_x, next_y}});
            }
        }
    }
}


int main() {
    FastIO

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    solve();

    cout << ans;

    return 0;
}