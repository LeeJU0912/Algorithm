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

vector<pair<int, int>> v;

bool compare(pair<int, int> a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	int i;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a; i++) {
		cin >> b >> c;
		v.push_back(make_pair(b, c));
	}
	
	sort(v.begin(), v.end(), compare);

	int g = v[0].second;
	int counter = 1;
	for (i = 1; i < v.size(); i++) {
		if (g <= v[i].first) {
			g = v[i].second;
			++counter;
		}
	}

	cout << counter << '\n';

	return 0;
}