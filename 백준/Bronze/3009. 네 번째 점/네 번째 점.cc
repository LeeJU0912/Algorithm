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

int point_x[1001];
int point_y[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a, b;

	for (i = 0; i < 3; i++) {
		cin >> a >> b;
		point_x[a] += 1;
		point_y[b] += 1;
	}
	for (i = 0; i < 1001; i++) {
		if (point_x[i] == 1) {
			cout << i << ' ';
			break;
		}
	}
	for (i = 0; i < 1001; i++) {
		if (point_y[i] == 1) {
			cout << i << ' ';
			break;
		}
	}

	return 0;
}