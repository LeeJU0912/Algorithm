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
#include <set>
#include <cstring>

using namespace std;

map<string, string> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a;
	int b;
	int i;
	string c, d;

	cin >> a >> b;
	for (i = 0; i < a; i++) {
		cin >> c >> d;
		m[c] = d;
	}
	for (i = 0; i < b; i++) {
		cin >> d;
		cout << m[d] << '\n';
	}
	
	return 0;
}