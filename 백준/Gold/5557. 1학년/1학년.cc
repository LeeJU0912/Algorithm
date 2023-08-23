#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
long long DP[100][21];

int main() {
	FastIO
	
	cin >> N;
	
	vector<int> save(N);
	
	for (int i = 0; i < N; i++) {
		cin >> save[i];
	}
	
	DP[0][save[0]] = 1;
	
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (DP[i - 1][j] == 0) continue;
			
			if (j + save[i] <= 20) {
				DP[i][j + save[i]] += DP[i - 1][j];
			}
			if (j - save[i] >= 0) {
				DP[i][j - save[i]] += DP[i - 1][j];
			}
		}
	}
	
	long long ans = DP[N - 2][save[N - 1]];
	
	cout << ans;
	
	return 0;
}