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

using namespace std;

int mape[101][101];
int a, b;
int mini = 100000;
int ans;

void Floyd() {
	int x, y, z;
	for (x = 1; x <= a; x++) {	// 가운데 노드가 제일 위에 있어야 함.
		for (y = 1; y <= a; y++) {
			for (z = 1; z <= a; z++) {
				if (mape[y][z] > mape[y][x] + mape[x][z]) {
					mape[y][z] = mape[y][x] + mape[x][z];
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, j;
	
	int c, d;

	cin >> a >> b;

	for (i = 1; i <= a; i++) {
		for (j = 1; j <= a; j++) {
			if (i != j) {
				mape[i][j] = 10000;
			}
		}
	}
	
	for (i = 1; i <= b; i++) {
		cin >> c >> d;
		mape[c][d] = 1;
		mape[d][c] = 1;
	}
	
	Floyd();

	for (i = 1; i <= a; i++) {
		int sum = 0;
		for (j = 1; j <= a; j++) {
			sum += mape[i][j];
		}
		if (sum < mini) {
			mini = sum;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}