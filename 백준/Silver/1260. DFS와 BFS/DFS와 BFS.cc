#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <functional>
#include <climits>

using namespace std;

int n, m, v;
int graph[1001][1001];
int visited[1001];
int visited2[1001];
queue<int>q;

void dfs(int start) {
	cout << start << ' ';
	visited[start] = 1;
	for (int i = 1; i < 1001; i++) {
		if (graph[start][i] != 0 && visited[i] == 0) {
			dfs(i);
		}
	}
}

void bfs(int start) {
	q.push(start);
	visited2[start] = 1;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << ' ';
		for (int i = 1; i < 1001; i++) {
			if (graph[current][i] != 0 && visited2[i] == 0) {
				q.push(i);
				visited2[i] = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(v);
	cout << '\n';
	bfs(v);

	return 0;
}