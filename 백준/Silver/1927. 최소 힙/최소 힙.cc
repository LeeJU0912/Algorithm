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

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	int i, g;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> b;
		if (b == 0) {
			if (q.size() == 0) {
				cout << "0" << '\n';
			}
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}
		else {
			q.push(b);
		}
	}

	return 0;
}