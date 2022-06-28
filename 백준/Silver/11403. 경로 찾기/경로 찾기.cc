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

int a;
int mape[101][101];

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
	
	int b;


	cin >> a;

	for (i = 1; i <= a; i++) {
		for (j = 1; j <= a; j++) {
			cin >> mape[i][j];
		}
	}
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= a; j++) {
			if (mape[i][j] == 0) {
				mape[i][j] = 10000;
			}
		}
	}

	Floyd();

	for (i = 1; i <= a; i++) {
		for (j = 1; j <= a; j++) {
			if (mape[i][j] == 10000) {
				cout << "0" << ' ';
			}
			else {
				cout << "1" << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}