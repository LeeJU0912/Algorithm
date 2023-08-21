#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> memo;
vector<int> costs;
int DP[101][10001];

int main() {
	FastIO
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		memo.push_back(temp);
	}
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		costs.push_back(temp);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 10000; j++) {
			int now_mem = memo[i - 1];
			int now_cost = costs[i - 1];
			
			if (now_cost <= j) {
				DP[i][j] = max(DP[i - 1][j - now_cost] + now_mem, DP[i - 1][j]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	
	for (int i = 0; i <= 10000; i++) {
		if (DP[N][i] >= M) {
			cout << i;
			break;
		}
	}
	
	return 0;
}