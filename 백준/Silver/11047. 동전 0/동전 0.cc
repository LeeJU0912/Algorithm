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

int coin[10];
int b;
int hap;

int plus1(int x) {
	if (x > b) return 0;
	hap += b / x;
	b %= x;
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a;

	cin >> a >> b;

	for (i = 0; i < a; i++) {
		cin >> coin[i];
	}
	for (i = a - 1; i >= 0; i--) {
		plus1(coin[i]);
	}

	cout << hap;
	return 0;
}