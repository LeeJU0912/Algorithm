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

int number[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	int b;
	int i, g;

	int counter = 0;

	cin >> a;

	for (i = 1; i <= a; i++) {
		cin >> b;
		if (counter == 0) {
			number[counter++] = b;
		}
		else {
			if (number[counter - 1] < b) {
				number[counter++] = b;
			}
			else {
				number[lower_bound(number, number + counter, b) - number] = b;
			}
		}
	}

	cout << counter;
	return 0;
}