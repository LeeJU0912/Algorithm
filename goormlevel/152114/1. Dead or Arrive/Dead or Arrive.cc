#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
pair<int, int> ans[1001];

int answer;

int main() {
	FastIO
		
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int v, w;
		cin >> v >> w;
		if (ans[v].first <= w) {
			ans[v].first = w;
			ans[v].second = i;
		}
	}
	
	for (int i = 1; i <= 1000; i++) {
		answer += ans[i].second;
	}
	
	cout << answer;
	
	return 0;
}