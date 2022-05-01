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

int dfsmap[1001][1001] = {};
int visit[1001] = {};
int answer;
int number;
int counter;

void dfs(int n) {
	counter++;
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

	cin >> number >> b;
	cin.ignore();

	for (i = 0; i < b; i++) {

		cin >> c >> d;
		dfsmap[c][d] = dfsmap[d][c] = 1;

	}
	g = 1;
	while (counter != number) {
		dfs(g);
		if (counter < number) {
			while (visit[g])
			++g;
		}
		answer++;
	}
	
	cout << answer << '\n';

	return 0;
}