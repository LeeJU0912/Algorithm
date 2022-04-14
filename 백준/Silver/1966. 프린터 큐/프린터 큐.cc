#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>

using namespace std;



int numlist[10000][100];

int toplist[10000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int i;
	int a, b, c;
	string d;
	int top = 0;
	int count;
	
	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		count = 0;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		cin >> b >> c;
		cin.ignore();

		getline(cin, d);

		for (int g = 0; g < b; g++) {
			q.push({d[g * 2] - 48, g});
			pq.push(d[g * 2] - 48);
		}

		while (!q.empty()) {
			int value = q.front().first;
			int location = q.front().second;
			
			q.pop();

			if (pq.top() == value) {
				pq.pop();
				++count;
				if (c == location) {
					cout << count << endl;
					break;
				}
			}
			else {
				q.push({ value, location });
			}
		}
	}
	return 0;
}