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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	string s;

	int g;
	int a, b;
	int check[20] = {};

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> s;
		if (s == "add") {
			cin >> b;
			check[b - 1] = 1;
		}
		else if (s == "remove") {
			cin >> b;
			check[b - 1] = 0;
		}
		else if (s == "check") {
			cin >> b;
			cout << check[b - 1] << '\n';
		}
		else if (s == "toggle") {
			cin >> b;
			if (check[b - 1] == 1) {
				check[b - 1] = 0;
			}
			else {
				check[b - 1] = 1;
			}
		}
		else if (s == "all") {
			for (g = 0; g < 20; g++) {
				check[g] = 1;
			}
		}
		else if (s == "empty") {
			for (g = 0; g < 20; g++) {
				check[g] = 0;
			}
		}
	}
	return 0;
}