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

int numlist[500000];
int maxvalue[250000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int i;
	int g;
	int a, b;
	double hap = 0;
	int counter = 0;
	int maxi = 0;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> b;
		numlist[i] = b + 4000;
		hap += numlist[i] - 4000;
	}
	if (hap / a < 0 && hap / a > -1) {
		hap = -1 * round((hap / a));
	}
	else {
		hap = round((hap / a));
	}

	sort(numlist, numlist + a);

	for (i = 0; i < a; i++) {
		++counter;
		if (i == a - 1 || numlist[i] != numlist[i + 1]) {
			if (counter > maxi) {
				g = 0;
				maxi = counter;
				maxvalue[g] = numlist[i];
			}
			else if (counter == maxi) {
				++g;
				maxvalue[g] = numlist[i];
			}
			counter = 0;
		}
	}

	cout << hap << '\n';
	cout << numlist[a / 2] - 4000 << '\n';

	if (g == 0) {
		cout << maxvalue[0] - 4000 << '\n';
	}
	else {
		cout << maxvalue[1] - 4000 << '\n';
	}
	
	cout << *max_element(numlist, numlist + a) - *min_element(numlist, numlist + a) << '\n';

	return 0;
}