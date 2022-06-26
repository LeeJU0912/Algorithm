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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a, b;
	int p = 1;

	cin >> a >> b;

	for (i = 1; i <= a; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	do {
		for (i = 0; i < b; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		reverse(v.begin() + b, v.end());
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}