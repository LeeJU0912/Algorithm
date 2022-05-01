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

vector<int> v[100000];
int visited[100001];
int temp[100001];
int counter = 2;

void dfs(int start) {
	visited[start] = 1;
	for (int i = 0; i < v[start].size(); i++) {
		int y = v[start][i];
		if (!visited[y]) {
			temp[y] = start;
			dfs(y);
		}
			
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	int i;

	cin >> a;
	cin.ignore();

	for (i = 0; i < a - 1; i++) {
		cin >> b >> c;
		v[b].push_back(c);
		v[c].push_back(b);
	}

	dfs(1);
	
	for (i = 2; i <= a; i++) {
		cout << temp[i] << '\n';
	}
	
	return 0;
}