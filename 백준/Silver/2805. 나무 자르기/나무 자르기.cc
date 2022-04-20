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

int tree[1000000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int i;
	int a, b;
	long long sum = 0;
	int max = 0;
	int min = 0;
	int mid;
	int temp;

	int start = 0;
	int last;

	cin >> a >> b;
	cin.ignore();


	for (i = 0; i < a; i++) {
		cin >> tree[i];
		if (tree[i] > max) {
			max = tree[i];
		}
	}

	last = max;

	while (start + 1 < last) {
		mid = (start + last) / 2;
		sum = 0;
		for (i = 0; i < a; i++) {
			temp = tree[i] - mid;
			if (temp > 0) {
				sum += temp;
			}
		}
		if (sum < b) {
			last = mid;
		}
		else {
			start = mid;
		}
	}
	
	cout << start << '\n';

	return 0;
}