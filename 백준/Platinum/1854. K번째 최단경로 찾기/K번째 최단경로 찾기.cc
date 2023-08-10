#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m, k;
vector<pair<int, int>> graph[1001];
int visited_count[1001];
int dist[1001];
int ans[1001];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({0, 1});
	
	while(!pq.empty()) {
		int now = pq.top().second;
		int now_cost = pq.top().first;
		pq.pop();
		
		if (visited_count[now] > k) continue;
		
		visited_count[now]++;
		
		if (visited_count[now] == k) {
			ans[now] = now_cost;
		}
		
		dist[now] = now_cost;
		
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			int next_cost = graph[now][i].first;
			
			if (visited_count[next] < k) {
				pq.push({dist[now] + next_cost, next});
			}
		}
	}
}

int main() {
	FastIO
	
	cin >> n >> m >> k;
	
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		graph[a].push_back({c, b});
	}
	
	for (int i = 1; i <= n; i++) {
		ans[i] = -1;
	}
	
	dijkstra();
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << '\n';
	}
	
	return 0;
}