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

	map<string, int> list;
	vector<string> namelist;
	int i;
	int a, b;
	int counter = 0;

	string c, d;

	cin >> a >> b;
	cin.ignore();


	for (i = 1; i <= a; i++) {
		cin >> c;
		list.insert(make_pair(c, i));
	}
	
	for (i = 1; i <= b; i++) {
		cin >> d;
		if (list.find(d) != list.end()) {
			namelist.push_back(d);
			counter += 1;
		}
	}
	sort(namelist.begin(), namelist.end());
	cout << counter << '\n';
	for (i = 0; i < namelist.size(); i++) {
		cout << namelist[i] << '\n';
	}
	return 0;
}