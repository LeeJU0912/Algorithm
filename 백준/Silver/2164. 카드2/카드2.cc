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
	int a;
	
	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		q.push(i + 1);
	}
	while (q.size() != 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front() << '\n';
	
	return 0;
}