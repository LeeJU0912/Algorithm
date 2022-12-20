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

int v[129][129];

int white;
int blue;

int papercut(int x, int y, int a) {
	int i, g;

	int counter = 0;
	for (i = y; i < y + a; i++) {
		for (g = x; g < x + a; g++) {
			counter += v[i][g];
		}
	}
	if (counter == 0) {
		white += 1;
		return 0;
	}
	else if (counter == a * a) {
		blue += 1;
		return 0;
	}

	else {
		papercut(x, y, a / 2);
		papercut(x, y + a / 2, a / 2);
		papercut(x + a / 2, y, a / 2);
		papercut(x + a / 2, y + a / 2, a / 2);
	}

	return 0;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	int i, g;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		for (g = 0; g < a; g++) {
			cin >> v[i][g];
		}
	}

	papercut(0, 0, a);

	cout << white << "\n" << blue << '\n';

	return 0;
}