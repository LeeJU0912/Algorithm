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
#include <array>
#include <functional>
#include <climits>

using namespace std;

int n, m;
int arr[9];
int save[9];

void dfs(int num, int start) {
	if (start == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) {
		arr[start] = save[i];
		dfs(i, start + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> save[i];
	}
	sort(save + 1, save + n + 1);	

	dfs(1, 0);

	return 0;
}