#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	map<string, int> pokelist;
	map<int, string> pokenum;
	int i, g;
	int a, b;

	string c, d;

	cin >> a >> b;
	cin.ignore();


	for (i = 1; i <= a; i++) {
		cin >> c;
		pokelist.insert(make_pair(c, i));	
		pokenum.insert(make_pair(i, c));
	}
	
	for (i = 1; i <= b; i++) {
		cin >> d;
		if (isdigit(d[0])) {
			cout << pokenum[stoi(d)] << '\n';
		}
		else {
			cout << pokelist[d] << '\n';
		}
	}

	return 0;
}