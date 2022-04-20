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

using namespace std;

int cable[10000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int i;
	int a, b;
    
	int cablemax;
	long max = 0;
	long min = 0;

	int sum = 0;

	int start = 0;
	long mid;
	int end = 0;

	cin >> a >> b;
	cin.ignore();


	for (i = 0; i < a; i++) {
		cin >> cable[i];
		if (cable[i] > max) {
			max = cable[i];
		}
	}
	
	max++;

	while (min < max) {
		mid = min + (max - min) / 2;
		sum = 0;
		for (i = 0; i < a; i++) {
			cable[i];
			sum += cable[i] / mid;
		}

		if (sum < b) {
			max = mid;
		}
		else {
			min = mid + 1;
		}
	}

	cout << min - 1 << '\n';

	return 0;
}