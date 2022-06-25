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

vector<int> v;
vector<int> temp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a, b;

	cin >> a >> b;

	for (i = 1; i <= a; i++) {
		v.push_back(i);
		if (i <= b) {
			temp.push_back(1);
		}
		else {
			temp.push_back(0);
		}
	}
	
	sort(temp.begin(), temp.end(), greater<>());

	do {
		for (i = 0; i < a; i++) {
			if (temp[i] == 1) {
				cout << v[i] << ' ';
			}
		}
		cout << '\n';
	} while (prev_permutation(temp.begin(), temp.end()));

	return 0;
}