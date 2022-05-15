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

int calc(int a) {
	int sum = a;
	while (a != 0) {
		sum += a % 10;
		a /= 10;
	}
	if (sum > 100) {
		return 0;
	}
	cout << sum << '\n';
	calc(sum);
	return 0;
}

int list[100];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i = 0;
	int g;

	int a;

	cin >> a;

	while (a != 0) {
		list[i] = a % 10;
		a /= 10;
		i++;
	}
	sort(list, list + i);

	for (g = i - 1; g >= 0; g--) {
		cout << list[g];
	}
	return 0;
}