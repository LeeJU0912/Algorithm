#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, g;

	int a, b;
	int sosu = 0;
	int counter;
	
	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		counter = 0;
		cin >> b;
		for (g = 1; g <= b; g++) {
			if (b % g == 0) {
				++counter;
			}
		}
		if (counter == 2) {
			sosu += 1;
		}
	}
	cout << sosu << '\n';

	return 0;
}