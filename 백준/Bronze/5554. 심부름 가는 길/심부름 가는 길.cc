#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {

	int sum = 0;	

	for(int i = 0; i < 4; i++) {

		int temp;

		cin >> temp;

		sum += temp;

	}

	cout << sum / 60 << '\n';

	cout << sum % 60;

	

	return 0;

}