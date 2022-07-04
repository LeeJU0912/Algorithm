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

using namespace std;

long long a, b;
int counter;
int answer = 1000000;

int solve(long long now, int counter) {
	if (now > b) {
		return 0;
	}
	else if (now == b) {
		answer = min(answer, counter);
		return 0;
	}

	solve(now * 2, counter + 1);
	solve(now * 10 + 1, counter + 1);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;

	solve(a, 1);
	if (answer == 1000000) {
		cout << "-1";
	}
	else {
		cout << answer;
	}
	return 0;
}