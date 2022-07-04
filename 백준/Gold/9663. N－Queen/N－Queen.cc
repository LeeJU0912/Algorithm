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
#include <functional>

using namespace std;

int n;
int counter;
int list[15];

int compare(int start) {
	for (int i = 0; i < start; i++) {
		if (list[start] == list[i] || start - i == abs(list[start] - list[i])) {
			return 0;
		}
	}
	return 1;
}

void nqueen(int start) {

	if (start == n) {
		counter++;
		return;
	}
	for (int i = 0; i < n; i++) {
		list[start] = i;
		if (compare(start)) {
			nqueen(start + 1);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	nqueen(0);

	cout << counter;
	
	return 0;
}