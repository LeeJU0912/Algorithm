#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int road[101][101];
int dist[101][101];

int main() {
	FastIO
	
	cin >> N;
	cin >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			dist[i][j] = 1e9;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		
		dist[b][a] = 1;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	
	for (int i = 1; i <= N; i++) {
		int counter = 0;
		
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (dist[i][j] == 1e9 && dist[j][i] == 1e9) counter++;
		}
		
		cout << counter << '\n';
	}
	
	return 0;
}