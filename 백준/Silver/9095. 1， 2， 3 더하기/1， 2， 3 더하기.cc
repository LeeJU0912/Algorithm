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

int dolist[11];

int doplus(int val) {
	int i;

	for (i = 4; i <= val; i++) {
		dolist[i] = dolist[i - 1] + dolist[i - 2] + dolist[i - 3];
	}

	return dolist[val];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, g;
	int val;
	int sum = 0;
	int a;

	dolist[1] = 1;
	dolist[2] = 2;
	dolist[3] = 4;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> val;

		sum = doplus(val);

		cout << sum << '\n';
	}

	
	return 0;
}