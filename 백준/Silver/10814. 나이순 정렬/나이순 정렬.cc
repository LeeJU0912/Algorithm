#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, string>> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int i;
	int order;
	int a;
	string b;
	
	cin >> order;
	cin.ignore();

	for (i = 0; i < order; i++) {
		cin >> a >> b;
		v.push_back(make_tuple(a, i + 1, b));
	}	

	sort(v.begin(), v.end());

	for (i = 0; i < order; i++) {
		cout << get<0>(v[i]) << " " << get<2>(v[i]) << '\n';
	}
	return 0;
}