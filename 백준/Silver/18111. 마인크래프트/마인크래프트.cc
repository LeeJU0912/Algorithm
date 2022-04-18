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

int worktime;
int temp = 100000000;
int minecraft[500][500];

void compare(int i, int target, int* block) {
	if (target > i) {
		worktime += (target - i) * 2;
		*block += target - i;
	}
	else if (target < i) {
		worktime += i - target;
		*block -= i - target;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int i;
	int g;
	int a, b, c, d;
	int gtemp;
	int counter = 0;
	int maxi = 0;
	int mini = 256;

	cin >> a >> b >> c;
	cin.ignore();
	d = c;
	
	for (i = 0; i < a; i++) {
		for (g = 0; g < b; g++) {
			cin >> minecraft[i][g];
			if (minecraft[i][g] > maxi) {
				maxi = minecraft[i][g];
			}
			if (minecraft[i][g] < mini) {
				mini = minecraft[i][g];
			}
		}
	}

	while (mini != maxi + 1) {
		worktime = 0;
		counter = 0;
		for (i = 0; i < a; i++) {
			if (counter == 1) {
				break;
			}
			for (g = 0; g < b; g++) {
				compare(mini, minecraft[i][g], &d);
				if (i == a - 1 && g == b - 1) {
					if (d < 0) {
						d = c;
						counter = 1;
						++mini;
						break;
					}
					if (worktime < temp) {
						temp = worktime;
						gtemp = mini;
					}
					else if (worktime == temp) {
						gtemp = mini;
					}
					d = c;
					++mini;
				}
			}
		}
	}
	
	cout << temp << " " << gtemp << '\n';

	return 0;
}