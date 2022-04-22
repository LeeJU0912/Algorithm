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

int person[1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a;
	int sum = 0;
	int temp = 0;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> person[i];
	}

	sort(person, person + a);

	for (i = 0; i < a; i++) {
		temp = temp + person[i];
		sum += temp;
	}

	cout << sum << '\n';
	return 0;
}