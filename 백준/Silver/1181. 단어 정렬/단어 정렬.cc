#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

bool compare(string a, string b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		return a < b;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i;
	int order;
	int a;
	string b[20000];
	int g;
	
	cin >> order;
	cin.ignore();

	for (i = 0; i < order; i++) {
		cin >> b[i];
	}	

	sort(b, b + order);
	sort(b, b + order, compare);

	for (i = 0; i < order - 1; i++) {
		if (b[i] == b[i + 1]) {
			continue;
		}
		cout << b[i] << '\n';
	}
	cout << b[order - 1] << '\n';

	return 0;
}