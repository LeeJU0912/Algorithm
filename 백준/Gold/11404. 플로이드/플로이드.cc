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

int n, m;
int city[101][101];

void Floyd() {
	for (int m = 1; m <= n; m++) {
		for (int s = 1; s <= n; s++) {
			for (int e = 1; e <= n; e++) {
				if (city[s][e] > city[s][m] + city[m][e]) {
					city[s][e] = city[s][m] + city[m][e];
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			city[i][j] = 1000000000;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (city[a][b] < c) {
			continue;
		}
		city[a][b] = c;
	}

	Floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || city[i][j] == 1000000000) {
				cout << "0" << ' ';
			}
			else {
				cout << city[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}