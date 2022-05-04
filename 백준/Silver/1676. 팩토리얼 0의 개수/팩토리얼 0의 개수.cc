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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	int b = 1;
	int i;
	int counter = 0;

	cin >> a;
	for (i = 0; i < a; i++) {
		if (b > 4200000) {
			b %= 1000000;
		}
		b *= a - i;
		while (b % 10 == 0) {
			b /= 10;
			counter += 1;
		}
	}
	cout << counter;
	return 0;
}