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
	int a;
	int check[1000];

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> check[i];
	}
	sort(check, check + a);

	for (i = 0; i < a; i++) {
		cout << check[i] << '\n';
	}

	return 0;
}