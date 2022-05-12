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

int matrix1[101][101];
int matrix2[101][101];

int result[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d;

	int i, g;
	
	int sum = 0;

	cin >> a >> b;

	for (i = 1; i <= a; i++) {
		for (g = 1; g <= b; g++) {
			cin >> matrix1[i][g];
		}
	}

	cin >> c >> d;

	for (i = 1; i <= c; i++) {
		for (g = 1; g <= d; g++) {
			cin >> matrix2[i][g];
		}
	}
	for (i = 1; i <= a; i++) {
		for (g = 1; g <= d; g++) {
			for (int j = 1; j <= b; j++) {
				result[i][g] += matrix1[i][j] * matrix2[j][g];
			}
		}
	}
	for (i = 1; i <= a; i++) {
		for (g = 1; g <= d; g++) {
			cout << result[i][g] << ' ';
		}
		cout << '\n';
	}

	return 0;
}