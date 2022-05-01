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

using namespace std;

int dfsmap[51][51] = {};
int visit[51][51] = {};
int answer;
int number;
int counter;
int garo, sero;
void dfs(int y, int x) {
	visit[y][x] = 1;
	if (x - 1 >= 0 && dfsmap[y][x - 1] && !visit[y][x - 1]) {
		dfs(y, x - 1);
	}
	if (x + 1 <= garo - 1 && dfsmap[y][x + 1] && !visit[y][x + 1]) {
		dfs(y, x + 1);
	}
	if (y + 1 <= sero - 1 && dfsmap[y + 1][x] && !visit[y + 1][x]) {
		dfs(y + 1, x);
	}
	if (y - 1 >= 0 && dfsmap[y - 1][x] && !visit[y - 1][x]) {
		dfs(y - 1, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d;
	int i, g, t;

	cin >> a;
	cin.ignore();
	for (int h = 0; h < a; h++) {
		counter = 0;
		answer = 0;
		memset(dfsmap, 0, sizeof(dfsmap));
		memset(visit, 0, sizeof(visit));

		cin >> garo >> sero >> b;
		cin.ignore();

		for (i = 0; i < b; i++) {

			cin >> c >> d;
			dfsmap[d][c] = 1;

		}
		g = 0;
		t = 0;
		for (int i = 0; i < sero; i++) {
			for (int j = 0; j < garo; j++) {
				if (dfsmap[i][j] == 1 && visit[i][j] == 0) {
					dfs(i, j);
					answer++;
				}
			}
		}
		cout << answer << '\n';
	}
	return 0;
}