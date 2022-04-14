#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int numlist[1000] = {};
	int a, b;
	int h = 0;
	
	cin >> a >> b;

	for (i = 0; i < a; i++) {
		q.push(i + 1);
	}
	while (q.size() != 0) {
		for (i = 0; i < b; i++) {
			if (i == b - 1) {
				numlist[h] = q.front();
				h += 1;
				q.pop();
				continue;
			}
			q.push(q.front());
			q.pop();
			
		}
	}
	cout << "<";
	for (i = 0; i < a - 1; i++) {
		cout << numlist[i];
		cout << ", ";
	}
	cout << numlist[a - 1];
	cout << ">" << '\n';

	return 0;
}