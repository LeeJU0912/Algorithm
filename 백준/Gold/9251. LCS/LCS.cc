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

int compare[1001][1001];

char a[1001];
char b[1001];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i, j;
	

	cin >> a;
	cin >> b;

	for (i = 0; i <= strlen(a); i++) {
		for (j = 0; j <= strlen(b); j++) {
			if (i == 0 || j == 0) {
				compare[i][j] = 0;
			}
			else if (a[i - 1] == b[j - 1]) {
				compare[i][j] = compare[i - 1][j - 1] + 1;
			}
			else {
				compare[i][j] = max(compare[i - 1][j], compare[i][j - 1]);
			}
		}
	}
	cout << compare[strlen(a)][strlen(b)];

	return 0;
}