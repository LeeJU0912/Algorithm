#include <iostream>
#include <queue>

using namespace std;

int main() {
	int i;
	int order;
	int sum, h;
	char line[100];
	deque<int> q;

	cin >> order;
	cin.ignore();

	for (i = 0; i < order; i++) {
		cin.getline(line, 100, '\n');

		if (line[0] == 'p' && line[1] == 'u' && line[2] == 's' && line[3] == 'h' && line[4] == '_' && line[5] == 'f' && line[6] == 'r' && line[7] == 'o' && line[8] == 'n' && line[9] == 't') {
			h = 11;
			sum = 0;
			while (line[h] != NULL) {
				sum = sum * 10 + (int(line[h]) - 48);
				h += 1;
			}
			q.push_front(sum);
		}
		else if (line[0] == 'p' && line[1] == 'u' && line[2] == 's' && line[3] == 'h' && line[4] == '_' && line[5] == 'b' && line[6] == 'a' && line[7] == 'c' && line[8] == 'k') {
			h = 10;
			sum = 0;
			while (line[h] != NULL) {
				sum = sum * 10 + (int(line[h]) - 48);
				h += 1;
			}
			q.push_back(sum);
		}
		else if (line[0] == 'p' && line[1] == 'o' && line[2] == 'p' && line[3] == '_' && line[4] == 'f' && line[5] == 'r' && line[6] == 'o' && line[7] == 'n' && line[8] == 't') {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
				q.pop_front();
			}
		}
		else if (line[0] == 'p' && line[1] == 'o' && line[2] == 'p' && line[3] == '_' && line[4] == 'b' && line[5] == 'a' && line[6] == 'c' && line[7] == 'k') {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << q.back() << endl;
				q.pop_back();
			}
		}
		else if (line[0] == 's' && line[1] == 'i' && line[2] == 'z' && line[3] == 'e') {
			cout << q.size() << endl;
		}
		else if (line[0] == 'e' && line[1] == 'm' && line[2] == 'p' && line[3] == 't' && line[4] == 'y') {
			if (q.size() == 0) cout << '1' << endl;
			else cout << "0" << endl;
		}
		else if (line[0] == 'f' && line[1] == 'r' && line[2] == 'o' && line[3] == 'n' && line[4] == 't') {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << q.front() << endl;
			}
		}
		else if (line[0] == 'b' && line[1] == 'a' && line[2] == 'c' && line[3] == 'k') {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else {
				cout << q.back() << endl;
			}
		}
	}

	return 0;
}