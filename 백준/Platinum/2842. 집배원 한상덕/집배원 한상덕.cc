#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<string> save;
bool visited[51][51];
int height_map[51][51];
vector<int> height;

int house_count;

pair<int, int> post;

int height_lowest;
int height_highest;


int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int solve(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= N) return 0;
	if (height_map[x][y] < height[height_lowest] || height_map[x][y] > height[height_highest]) return 0;
	if (visited[x][y]) return 0;
	visited[x][y] = true;
	
	int counter = save[x][y] == 'K';
	
	for (int i = 0; i < 8; i++) {
		counter += solve(x + dx[i], y + dy[i]);
	}
	return counter;
}

int main() {
	FastIO
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		
		save.push_back(s);
		
		for (int j = 0; j < N; j++) {
			if (s[j] == 'P') {
				post = {i, j};
			}
			else if (s[j] == 'K') {
				house_count++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> height_map[i][j];
			height.push_back(height_map[i][j]);
		}
	}
	
	sort(height.begin(), height.end());
	height_lowest = 0;
	height_highest = 0;
	
	int ans = INT_MAX;
	
	while (height_lowest < height.size() && height_highest < height.size()) {
		memset(visited, false, sizeof(visited));
		if (solve(post.first, post.second) == house_count) {
			ans = min(ans, height[height_highest] - height[height_lowest]);
			height_lowest++;
		}
		else height_highest++;
	}
	
	cout << ans;
	
	return 0;
}