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

int stair[301];
int a;
int save[301];

void jump() {
	save[1] = stair[1];
	save[2] = stair[1] + stair[2];
	for (int i = 3; i <= a; i++) {
		save[i] = max(save[i - 2] + stair[i], save[i - 3] + stair[i - 1] + stair[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, j;

	int counter = 0;

	cin >> a;

	for (i = 1; i <= a; i++) {
		cin >> stair[i];
	}
	if (a == 1) {
		cout << stair[1];
		return 0;
	}
	jump();
	cout << save[a];
	return 0;
}