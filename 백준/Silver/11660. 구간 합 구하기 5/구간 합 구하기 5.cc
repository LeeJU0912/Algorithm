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

int num_list[1025][1025];
int hap_garo[1025][1025];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;

	int x1, y1, x2, y2;

	int i, g;
	
	int sum = 0;

	cin >> a >> b;

	for (i = 1; i <= a; i++) {
		for (g = 1; g <= a; g++) {
			cin >> num_list[i][g];
			hap_garo[i][g] = hap_garo[i][g - 1] + num_list[i][g];
		}
	}
	for (i = 1; i <= b; i++) {
		sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (g = x1; g <= x2; g++) {
			sum += hap_garo[g][y2] - hap_garo[g][y1 - 1];
		}
		cout << sum << '\n';
	}

	return 0;
}