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

int list[100001];

int selfnum(int x) {
	if (x > 10000) {
		return 0;
	}
	int sum = 0;
	sum += x;
	list[x] = 1;
	while (x != 0) {
		sum += (x % 10);
		x /= 10;
	}
	selfnum(sum);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a, b;

	for (i = 1; i <= 10000; i++) {
		if (list[i] == 0) {
			selfnum(i);
			list[i] = 0;
			cout << i << '\n';
		}
	}

	return 0;
}