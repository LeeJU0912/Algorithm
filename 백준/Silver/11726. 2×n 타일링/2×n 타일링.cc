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

int num[1001];

int doplus(int length) {

	int i;
	
	for (i = 3; i <= length; i++) {
		num[i] = num[i - 2] + num[i - 1];
		if (num[i] >= 10007) {
			num[i] = num[i] % 10007;
		}
	}
	
	return num[length];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;

	cin >> a;
	cin.ignore();

	num[1] = 1;
	num[2] = 2;

	doplus(a);

	cout << doplus(a) << '\n';

	return 0;
}