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

int numlist[100000];
int compare[100000];

bool binarysearch(int* arr, int length, int value) {

	if (arr == nullptr || length < 0)
		return 0;

	int left = 0;
	int right = length - 1;
	int mid;

	while (left <= right) {
		mid = (right + left) / 2;

		if (arr[mid] == value) {
			return 1;
		}
		else if (arr[mid] < value) {
			left = mid + 1;
		}
		else if (arr[mid] > value) {
			right = mid - 1;
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int i;
	int a, b;
	
	
	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> numlist[i];
	}

	sort(numlist, numlist + a);

	cin >> b;

	for (i = 0; i < b; i++) {
		cin >> compare[i];
		if (binarysearch(numlist, a, compare[i])) {
			compare[i] = 1;
		}
		else {
			compare[i] = 0;
		}
	}

	for (i = 0; i < b; i++) {
		cout << compare[i] << '\n';
	}

	return 0;
}