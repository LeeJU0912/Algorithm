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
int number_list[1000001];
int indexe[1000001];
int ans[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	int b;
	int i, g;

	int counter = 0;

	cin >> a;

	for (i = 1; i <= a; i++) {
		cin >> b;
		number_list[i] = b;
		if (counter == 0) {
			number[counter++] = b;
			indexe[i] = 0;
		}
		else {
			if (number[counter - 1] < b) {
				indexe[i] = counter;
				number[counter++] = b;
				
			}
			else {
				number[lower_bound(number, number + counter, b) - number] = b;
				indexe[i] = lower_bound(number, number + counter, b) - number;
			}
		}
	}

	int t = 0;
	cout << counter << '\n';
	for (int i = a; i >= 1; i--) {
		if (counter == indexe[i] + 1) {
			ans[t++] = number_list[i]; counter--;
		}
	}
	for (int i = t - 1; i >= 0; i--) cout << ans[i] << ' ';

	return 0;
}