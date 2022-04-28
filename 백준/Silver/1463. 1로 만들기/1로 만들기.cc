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

using namespace std;

int dp[1000001];

int makeone(int target) {
	int num = 4;
	while (num != target + 1) {
		dp[num] = dp[num - 1] + 1;
		if (num % 2 == 0) dp[num] = min(dp[num], dp[num / 2] + 1);
		if (num % 3 == 0) dp[num] = min(dp[num], dp[num / 3] + 1);
		++num;
	}

	return dp[target];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	
	cin >> a;
	cin.ignore();

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	
	if (a > 3) {
		makeone(a);
	}
	
	cout << dp[a] << '\n';

	return 0;
}