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

int hap = 1;

int facto(int x) {
	if (x == 0) return 0;
	hap *= x;
	facto(x - 1);
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;

	cin >> a;

	facto(a);

	cout << hap;

	return 0;
}