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

typedef vector<vector<long long>> matrix;

const long long MOD = 1000000007LL;

matrix operator* (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c (n, vector<long long>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= MOD;
		}
	}
	return c;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long n;

	cin >> n;

	if (n <= 1) {
		cout << n;
		return 0;
	}

	matrix ans = { {1, 0}, {0, 1} };
	matrix a = { {1, 1}, {1, 0} };

	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}
	cout << ans[0][1];

	return 0;
}