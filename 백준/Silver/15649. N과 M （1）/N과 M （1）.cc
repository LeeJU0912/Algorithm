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

int number[9];
bool visited[9];
int a, b;

void dfs(int start) {
	if (start == b) {
		for (int i = 0; i < b; i++) {
			cout << number[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= a; i++) {
		if (!visited[i]) {
			visited[i] = true;
			number[start] = i;
			dfs(start + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
    cin.ignore();
    
	dfs(0);

	return 0;
}