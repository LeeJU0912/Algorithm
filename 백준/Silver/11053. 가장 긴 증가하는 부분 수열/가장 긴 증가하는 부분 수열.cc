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

using namespace std;

int number[1001];
int length[1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	int b;
	int i, g;

	cin >> a;

	for (i = 1; i <= a; i++) {
		cin >> b;
		number[i] = b;
	}
	for (i = 1; i <= a; i++) {
		int max = 0;
		for (g = 0; g < i; g++) {
			if (number[i] > number[g]) {
				if (max < length[g]) {
					max = length[g];
				}
			}
			length[i] = max + 1;
		}

	}
	
	cout << *max_element(length, length + a + 1);
	return 0;
}