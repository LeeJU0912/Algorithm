#include <iostream>

using namespace std;

int main() {
	int num;
	int i;
	int x;
	int counter;
	char order[100];


	cin >> num;
	cin.ignore();

	for (i = 0; i < num; i++) {
		counter = 0;
		x = 0;
		cin.getline(order, 100, '\n');
		if (order[0] == ')') {
			cout << "NO" << endl;
			continue;
		}
		while (order[x] != NULL) {
			if (order[x] == '(') {
				counter += 1;
				x += 1;
			}
			else {
				if (counter == 0 && order[x] == ')') {
					cout << "NO" << endl;
					break;
				}
				counter -= 1;
				x += 1;
			}
		}
		if (counter == 0 && order[x] == NULL) {
			cout << "YES" << endl;
		}
		else if (counter != 0) {
			cout << "NO" << endl;
		}
	}

	return 0;
}