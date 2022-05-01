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

using namespace std;

int dfsmap[101][101] = {};
int visit[101] = {};
int answer;
int number;

void dfs(int n) {
	answer++;
	visit[n] = 1;
	for (int i = 1; i <= number; i++) {
		if (dfsmap[n][i] && !visit[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d;
	int i, g;

	cin >> number;
	cin.ignore();
	cin >> b;
	cin.ignore();

	for (i = 0; i < b; i++) {

		cin >> c >> d;
		dfsmap[c][d] = dfsmap[d][c] = 1;

	}
	dfs(1);
	cout << answer - 1 << '\n';

	return 0;
}