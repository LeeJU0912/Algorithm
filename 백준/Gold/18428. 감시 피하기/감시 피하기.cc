#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int board[6][6];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool ans;

vector<pair<int, int>> teacher;

void solve() {
	for (int i = 0; i < teacher.size(); i++) {
		auto now = teacher[i];
		
		for (int j = 0; j < 4; j++) {
			for (int k = 1; k < N; k++) {
				int next_x = now.first + dx[j] * k;
				int next_y = now.second + dy[j] * k;
				
				if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) break;
				
				if (board[next_x][next_y] == -1) break;
				
				if (board[next_x][next_y] == -2) {
					return;
				}
			}
		}
	}
	
	ans = true;
}

void make_O(int counter) {
	if (counter == 3) {
		solve();
		return;
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] < 0) continue;
			board[i][j] = -1;
			make_O(counter + 1);
			board[i][j] = 0;
		}
	}
}

int main() {
	FastIO
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			
			if (c == 'T') {
				teacher.push_back({i, j});
				board[i][j] = -3;
			}
			else if (c == 'S') {
				board[i][j] = -2;
			}
			else if (c == 'O') {
				board[i][j] = -1;
			}
		}
	}
	
	make_O(0);
	
	if (!ans) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	
	return 0;
}