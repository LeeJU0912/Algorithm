#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int board[15][15];
int chk[15][15];
int ans;

void visit_plus(int x, int y) {
	int counter = 1;
	while(x + counter < N && y + counter < N) {
		chk[x + counter][y + counter]++;
		counter++;
	}
	
	counter = 1;
	while(x + counter < N && y - counter >= 0) {
		chk[x + counter][y - counter]++;
		counter++;
	}
	
	for (int i = x + 1; i < N; i++) {
		chk[i][y]++;
	}
}

void visit_minus(int x, int y) {
	int counter = 1;
	while(x + counter < N && y + counter < N) {
		chk[x + counter][y + counter]--;
		counter++;
	}
	
	counter = 1;
	while(x + counter < N && y - counter >= 0) {
		chk[x + counter][y - counter]--;
		counter++;
	}
	
	for (int i = x + 1; i < N; i++) {
		chk[i][y]--;
	}
}

void solve(int x, int y) {
	if(x == N - 1) {
		ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (chk[x + 1][i]) continue;
		visit_plus(x + 1, i);
		solve(x + 1, i);
		visit_minus(x + 1, i);
	}
}

int main() {
	FastIO
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		visit_plus(0, i);
		solve(0, i);
		visit_minus(0, i);
	}
	
	cout << ans;
	
	return 0;
}