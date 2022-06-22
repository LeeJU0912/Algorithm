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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i = 0;
	int a = 1;
	int b = 1;

	while (!(a == 0 && b == 0)) {
		cin >> a >> b;
		if (a == 0 && b == 0) {
			return 0;
		}
		if (a != 0 && b % a == 0) {
			cout << "factor" << '\n';
		}
		else if (b != 0 && a % b == 0) {
			cout << "multiple" << '\n';
		}
		else {
			cout << "neither" << '\n';
		}
	}

	return 0;
}