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

int numlist[20000001];
int compare[500000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int i;
	int a, b, c;
	
	
	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> c;
		c += 10000000;
		++numlist[c];
	}

	cin >> b;

	for (i = 0; i < b; i++) {
		cin >> compare[i];
	}

	for (i = 0; i < b; i++) {
		cout << numlist[compare[i] + 10000000] << '\n';
	}

	return 0;
}