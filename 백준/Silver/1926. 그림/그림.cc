#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
int board[501][501];
bool visited[501][501];
int picture;
int ans;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y) {
	picture++;
	
	int counter = 0;
	
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;
	
	while(!q.empty()) {
		auto now = q.front();
		q.pop();
		
		counter++;
		
		for (int i = 0; i < 4; i++) {
			int next_x = now.first + dx[i];
			int next_y = now.second + dy[i];
			
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
			if (board[next_x][next_y] == 0) continue;
			if (visited[next_x][next_y]) continue;
			visited[next_x][next_y] = true;
			q.push({next_x, next_y});
		}
	}
	
	ans = max(ans, counter);
}

int main() {
	FastIO
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j]) continue;
			if (board[i][j] == 0) continue;
			bfs(i, j);
		}
	}
	
	cout << picture << '\n';
	cout << ans;
	
	return 0;
}