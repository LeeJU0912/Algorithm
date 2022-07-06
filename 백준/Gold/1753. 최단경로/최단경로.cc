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

int d[20001];
int n, m, start;

vector<pair<int, int>> graph[300001];

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start] = 0;	//출발점 -> 출발점은 반드시 최소거리가 0이다.
	pq.push({ d[start], start });	//출발점 설정 (지금까지 쌓인 거리 ,시작점)


	while (!pq.empty()) {	//더 이상 갈 곳이 없을 때까지 반복
		int dist = pq.top().first;	//지나간 간선들 가중치 합계
		int now = pq.top().second;	//현재 위치
		pq.pop();

		if (dist > d[now]) continue;	//현재 위치로 오는 여러 간선들 중에 가중치가 가장 작은 거만 고르기


		for (int i = 0; i < graph[now].size(); i++) {	//지금 점과 연결된 모든 간선들로 뻗어나가기
			int nidx = graph[now][i].first;	//다음 점의 위치
			int cost = graph[now][i].second;	//다음 점까지 가는데 걸린 가중치
			

			if (dist + cost < d[nidx]) {	//만약 (지금까지 가중치 합 + 다음점까지의 가중치) 가 (다음점까지의 기존의 가중치 합) 보다 작다면
				d[nidx] = dist + cost;	//(다음점에서의 최소 가중치) 를 (지금까지의 가중치 합 + 다음점까지의 가중치) 로 설정
				pq.push(make_pair(d[nidx], nidx));	//다음 점이 최소거리일 경우, 그 점을 출발점으로 잡고 다시 다음 점들을 향해 출발
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> start;

	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	fill_n(d, 20001, INT_MAX);

	dijkstra();

	for (int i = 1; i <= n; i++) {
		if (d[i] == INT_MAX) {
			cout << "INF" << '\n';
		}
		else {
			cout << d[i] << '\n';
		}
	}
	return 0;
}