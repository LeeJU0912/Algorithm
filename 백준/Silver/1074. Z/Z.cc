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

int b;
int c;
int check;

int counter;

int papercut(int x, int y, int a) {
	int i, g;
	if (check == 1) {
		return 0;
	}
	if (x + a < c || y + a < b) {
		counter += a * a;
		return 0;
	}
	else if (a != 2) {
		papercut(x, y, a / 2);
		papercut(x + a / 2, y, a / 2);
		papercut(x, y + a / 2, a / 2);
		papercut(x + a / 2, y + a / 2, a / 2);
	}
	else {
		for (i = y; i <= y + 1; i++) {
			for (g = x; g <= x + 1; g++) {
				++counter;
				if (i == b && g == c) {
					cout << counter - 1 << '\n';
					check = 1;
					return 0;
				}
			}
		}
	}

	return 0;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	int i;

	cin >> a >> b >> c;
	cin.ignore();

	int d = 1;
	for (i = 0; i < a; i++) {
		d *= 2;
	}

	papercut(0, 0, d);
	return 0;
}