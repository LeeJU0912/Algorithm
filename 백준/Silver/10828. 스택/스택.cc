#include <iostream>

int box[10000];

int main() {
	int num;
	int i;
	int x = 5;
	int sum = 0;
	int counter = 0;
	char order[100];


	std::cin >> num;
	std::cin.ignore();

	for (i = 0; i < num; i++) {
		std::cin.getline(order, 100, '\n');
		if (order[0] == 'p' && order[1] == 'u' && order[2] == 's' && order[3] == 'h') {
			x = 5;
			sum = 0;
			while (order[x] != NULL) {
				sum = sum * 10;
				sum = sum + int(order[x]) - 48;
				x += 1;
			}
			box[counter] = sum;
			counter += 1;
		}
		else if (order[0] == 't' && order[1] == 'o' && order[2] == 'p') {
			if (counter == 0) {
				std::cout << "-1" << std::endl;
			}
			else {
				std::cout << box[counter - 1] << std::endl;
			}
		}
		else if (order[0] == 's' && order[1] == 'i' && order[2] == 'z' && order[3] == 'e') {
			std::cout << counter << std::endl;
		}
		else if (order[0] == 'p' && order[1] == 'o' && order[2] == 'p') {
			if (counter == 0) {
				std::cout << "-1" << std::endl;
			}
			else {
				std::cout << box[counter - 1] << std::endl;
				counter -= 1;
			}
		}
		else if (order[0] == 'e' && order[1] == 'm' && order[2] == 'p' && order[3] == 't' && order[4] == 'y') {
			if (counter == 0) {
				std::cout << "1" << std::endl;
			}
			else {
				std::cout << "0" << std::endl;
			}
		}

	}

	return 0;
}