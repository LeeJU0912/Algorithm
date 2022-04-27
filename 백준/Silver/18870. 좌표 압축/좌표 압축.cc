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

map<int, int> m;

int num[1000000];
int num2[1000000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	int i;
	int min = 1000000001;
	int counter = 1;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> b;
		num[i] = b;
		num2[i] = b;
	}

	sort(num2, num2 + a);

	for (i = 0; i < a; i++) {
		if (i == 0) {
			m.insert(pair<int, int>(num2[0], 0));
		}
		else if (num2[i - 1] < num2[i]) {
			m.insert(pair<int, int>(num2[i], counter));
			++counter;
		}
	}

	for (i = 0; i < a; i++) {
		c = m.find(num[i])->second;
		cout << c << " ";
	}

	return 0;
}