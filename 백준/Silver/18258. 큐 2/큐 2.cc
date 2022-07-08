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
#include <functional>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	string c;

	queue<int> q;

	cin >> a;

	for (int i = 1; i <= a; i++) {
		cin >> c;
		if (c == "push") {
			cin >> b;
			q.push(b);
		}
		else if (c == "pop") {
			if (q.size() == 0) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if (c == "size") {
			cout << q.size() << '\n';
		}
		else if (c == "empty") {
			cout << q.empty() << '\n';
		}
		else if (c == "front") {
			if (q.size() == 0) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
		else if (c == "back") {
			if (q.size() == 0) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.back() << '\n';
		}
	}

	return 0;
}