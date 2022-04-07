#include <iostream>

using namespace std;

int main() {
	int i;
	int h;
	int y;
	char e[101];
	int ho[101];

	while (1) {
		cin.getline(e, 101, '\n');

		if (e[0] == '.' && e[1] == NULL) {
			break;
		}

		i = 0;
		h = 0;
		y = 0;
		while (e[i] != NULL) {
			if (e[i] == '(') {
				ho[h] = 1;
				h += 1;
			}
			else if (e[i] == '[') {
				ho[h] = 2;
				h += 1;
			}
			else if (e[i] == ')' && h == 0) {
				h = -1;
				break;
			}
			else if (e[i] == ']' && h == 0) {
				h = -1;
				break;
			}
			else if (e[i] == ')' && ho[h - 1] == 1) {
				h -= 1;
			}
			else if (e[i] == ']' && ho[h - 1] == 2) {
				h -= 1;
			}
			else if (e[i] == ']' && ho[h - 1] == 1) {
				h = -1;
				break;
			}
			else if (e[i] == ')' && ho[h - 1] == 2) {
				h = -1;
				break;
			}
			i += 1;
		}
		if (h == 0) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}