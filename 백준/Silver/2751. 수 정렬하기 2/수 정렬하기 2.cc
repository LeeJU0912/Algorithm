#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int number[1000000];

int main() {
	ios_base::sync_with_stdio(false);
	int i;
	int order;
	

	cin >> order;
	cin.ignore();

	for (i = 0; i < order; i++) {
		cin >> number[i];
	}
    
	sort(number, number + order);

	for (i = 0; i < order; i++) {
		cout << number[i] << '\n';
	}
	return 0;
}