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

int num_list[2][100000];
int maxi[2][100000];

int a, b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, g;

	cin >> a;
	

	for (i = 0; i < a; i++) {
		cin >> b;
		for (g = 0; g < b; g++) {
			cin >> num_list[0][g];
		}
		for (g = 0; g < b; g++) {
			cin >> num_list[1][g];
		}
		for (int x = b - 1; x >= 0; x--) {
			for (int y = 0; y < 2; y++) {
				if (maxi[y][x]) continue;
				if (x == b - 1) {
					maxi[y][x] = num_list[y][x];
				}
				if (y == 0) {
					maxi[y][x] = max(maxi[y + 1][x + 1], maxi[y + 1][x + 2]) + num_list[y][x];
				}
				else {
					maxi[y][x] = max(maxi[y - 1][x + 1], maxi[y - 1][x + 2]) + num_list[y][x];
				}
				
			}
		}
		cout << max(maxi[0][0], maxi[1][0]) << '\n';
		memset(num_list, 0, sizeof(num_list));
		memset(maxi, 0, sizeof(maxi));
	}

	return 0;
}