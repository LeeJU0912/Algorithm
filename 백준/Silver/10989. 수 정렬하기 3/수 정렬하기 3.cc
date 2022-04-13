#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int number[10000] = {};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i;
	int order;
	int a;
	int b = 0;
	int g;
	
	cin >> order;
	cin.ignore();

	for (i = 0; i < order; i++) {
		cin >> a;
		if (a > b) {
			b = a;
		}
		number[a - 1] += 1;
		
	}

	for (i = 0; i < b; i++) {
		for (g = 0; g < number[i]; g++) {
			cout << i + 1 << '\n';
		}
	}
	return 0;
}