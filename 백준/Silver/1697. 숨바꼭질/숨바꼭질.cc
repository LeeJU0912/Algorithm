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

int visit[1000000];

void bfs(int start, int end) {
	queue<pair<int, int>> q;
	q.push({ start, 0 });
	visit[start] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();
		if (x < 0 || x > 100000) continue;
		if (x == end) {
			cout << time;
			break;
		}

		int a = x - 1;
		if (!visit[a]) {
			q.push({ a, time + 1 });
			visit[a] = true;
		}

		int b = x + 1;
		if (!visit[b]) {
			q.push({ b, time + 1 });
			visit[b] = true;
		}

		int c = x * 2;
		if (!visit[c]) {
			q.push({ c, time + 1 });
			visit[c] = true;
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;

	cin >> a >> b;
	bfs(a, b);

	return 0;
}