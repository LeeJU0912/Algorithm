#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct INFO {
    int x, y, mini, maxi;
};

bool operator < (const INFO& a, const INFO& b) {
    return a.maxi - a.mini > b.maxi - b.mini;
}

int n;
int board[100][100];
int DP[100][100][201];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans = 200;

bool solve(int limit) {
    priority_queue<INFO> pq;
    pq.push({0, 0, board[0][0], board[0][0]});
    DP[0][0][board[0][0]] = 0;

    while(!pq.empty()) {
        INFO now = pq.top();
        pq.pop();
        
        if (now.maxi - now.mini > limit) continue;

        if (now.x == n - 1 && now.y == n - 1) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = now.x + dx[i];
            int nextY = now.y + dy[i];

            if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;

            int nextMini = min(now.mini, board[nextX][nextY]);
            int nextMaxi = max(now.maxi, board[nextX][nextY]);

            if (DP[nextX][nextY][nextMini] <= nextMaxi - nextMini) continue;

            DP[nextX][nextY][nextMini] = nextMaxi - nextMini;

            pq.push({nextX, nextY, nextMini, nextMaxi});
        }
    }

    return false;
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int start = 0;
    int end = 200;

    while(start <= end) {
        int mid = (start + end) / 2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k <= 200; k++) {
                    DP[i][j][k] = 200;
                }
            }
        }

        if (solve(mid)) {
            end = mid - 1;
            ans = mid;
        }
        else {
            start = mid + 1;
        }
    }
    
    cout << ans;

    return 0;
}