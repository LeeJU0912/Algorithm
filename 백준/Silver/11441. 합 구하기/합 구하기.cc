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

int number[100001];
int hap[100001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c, d;

	int i, g;

	cin >> a;

	for (i = 1; i <= a; i++) {
		cin >> number[i];
		hap[i] = hap[i - 1] + number[i];
	}
	cin >> b;
	for (i = 1; i <= b; i++) {
		cin >> c >> d;
		cout << hap[d] - hap[c - 1] << '\n';
	}

	return 0;
}