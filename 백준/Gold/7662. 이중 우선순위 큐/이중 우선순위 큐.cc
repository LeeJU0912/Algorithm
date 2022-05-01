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

using namespace std;

multiset <int> v;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, d;
	int i, g;
	string c;

	int size;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		size = 0;
		cin >> d;
		for (g = 0; g < d; g++) {
			cin >> c >> b;
			if (c == "D" && b == -1) {
				if (size == 0) {
					continue;
				}
				else {
					v.erase(v.begin());
					size -= 1;
				}
			}
			else if (c == "D" && b == 1) {
				if (size == 0) {
					continue;
				}
				else {
					v.erase(--v.end());
					size -= 1;
				}
			}
			else {
				v.insert(b);
				size += 1;
			}
		}

		if (size == 0) {
			cout << "EMPTY" << '\n';
		}
		else {
			auto iter = v.begin();
			auto iter2 = v.end();
			--iter2;
			cout << *iter2 << " " << *iter << '\n';
		}
		v.clear();
	}

	return 0;
}