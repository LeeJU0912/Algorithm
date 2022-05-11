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

int temp[501][501];
int maxi[501][501];
int a;

void calculate(int i) {
	if (i == a) {
		for (int g = 0; g < i; g++) {
			maxi[i][g] = temp[i][g];
		}
	}

	if (i == 1) return;
	

	for (int g = 0; g < i - 1; g++) {
		maxi[i - 1][g] = max(maxi[i][g], maxi[i][g + 1]) + temp[i - 1][g];
	}
	calculate(i - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	int i, g;

	cin >> a;

	for (i = 1; i <= a; i++) {
		for (g = 0; g < i; g++) {
			cin >> temp[i][g];
		}
	}
	calculate(a);

	cout << maxi[1][0] << '\n';

	return 0;
}