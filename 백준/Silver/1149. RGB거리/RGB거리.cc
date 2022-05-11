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

int temp[1001][3];
int house[1001][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	int i;

	cin >> a;

	for (i = 1; i <= a; i++) {
		cin >> temp[i][0] >> temp[i][1] >> temp[i][2];
		house[i][0] = min(house[i - 1][1], house[i - 1][2]) + temp[i][0];
		house[i][1] = min(house[i - 1][0], house[i - 1][2]) + temp[i][1];
		house[i][2] = min(house[i - 1][1], house[i - 1][0]) + temp[i][2];
	}

	cout << min(house[a][0], min(house[a][1], house[a][2])) << '\n';

	return 0;
}