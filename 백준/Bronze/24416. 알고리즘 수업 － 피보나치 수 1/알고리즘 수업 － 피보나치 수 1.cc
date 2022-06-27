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
#include <set>
#include <cstring>
#include <array>

using namespace std;

int counter1;
int counter2;
int f[41];

int fibonacci(int x) {
	int i;
	f[1] = 1;
	f[2] = 1;
	for (i = 3; i <= x; i++) {
		f[i] = f[i - 1] + f[i - 2];
		counter2++;
	}
	return f[x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a;

	cin >> a;


	int c = fibonacci(a);

	cout << c << ' ' << counter2;

	return 0;
}