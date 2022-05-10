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

long long temp;
long long temp2;

long long mit;

long long divide;

long long times(long long n) {
	if (n == 0) return 1;

	temp = times(n / 2);
	temp2 = temp * temp % divide;

	if (n % 2 == 0) {
		return temp * temp % divide;
	}
	else if (n % 2 == 1) {
		return (temp * temp % divide * mit) % divide;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long a;
	long long c;

	cin >> mit >> a >> divide;

	c = times(a);

	cout << c << '\n';

	return 0;
}