#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i;
	int order;
	int a;
	int b;
	int g;
	
	cin >> order;
	cin.ignore();

	for (i = 0; i < order; i++) {
		cin >> b >> a;
		v.push_back(pair<int, int>(a, b));		
	}

	sort(v.begin(), v.end());

	for (i = 0; i < order; i++) {
		cout << v[i].second << " " << v[i].first << '\n';
	}
	return 0;
}