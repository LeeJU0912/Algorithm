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

int fibo_zero[41];
int fibo_one[41];

int fibonacci(int n) {

	for (int i = 2; i <= n; i++) {
		fibo_zero[i] = fibo_zero[i - 1] + fibo_zero[i - 2];
		fibo_one[i] = fibo_one[i - 1] + fibo_one[i - 2];
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, g;
	int val[10000];
	int sum = 0;
	int a;

	int maxi = 0;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> val[i];

		if (val[i] > maxi) {
			maxi = val[i];
		}
	}
	fibo_zero[0] = 1;
	fibo_one[1] = 1;
	fibonacci(maxi);

	for (i = 0; i < a; i++) {
		cout << fibo_zero[val[i]] << " " << fibo_one[val[i]] << '\n';
	}
	
	return 0;
}