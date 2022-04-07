#include <iostream>

using namespace std;

int box[100000];

int main() {
	int num;
	int i;
	int h = 0;
	int y;
	int sum = 0;


	cin >> num;
	cin.ignore();

	for (i = 0; i < num; i++) {
		cin >> y;
		if (y == 0) h -= 1;
		else {
			box[h] = y;
			h += 1;
		}
	}

	for (i = 0; i < h; i++) {
		sum += box[i];
	}

	cout << sum << endl;

	return 0;
}