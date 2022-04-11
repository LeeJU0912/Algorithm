#include <iostream>
#include <stack>

using namespace std;

int numlist[200000];
char temp[200001];
stack<int> q;

int main() {
	int i;
	int g;
	int h = 0;
	int order;
	int min = 0;
	int counter = 0;

	cin >> order;
	cin.ignore();

	for (i = 0; i < order; i++) {
		cin >> numlist[i];
	}

	while (counter != numlist[0]) {
		counter += 1;
		q.push(counter);
		temp[h] = '+';
		h += 1;
	}
	for (i = 0; i < order - 1; i++) {
		if (numlist[i] > numlist[i + 1]) {
			q.pop();
			temp[h] = '-';
			h += 1;
			if (q.top() != numlist[i + 1]) {
				cout << "NO" << '\n';
				return 0;
			}
		}
		else {
			q.pop();
			temp[h] = '-';
			h += 1;
			while (counter != numlist[i + 1]) {
				counter += 1;
				q.push(counter);
				temp[h] = '+';
				h += 1;
			}
		}
	}
	temp[h] = '-';
	h += 1;

	for (i = 0; i < h; i++) {
		cout << temp[i] << '\n';
	}

	return 0;
}