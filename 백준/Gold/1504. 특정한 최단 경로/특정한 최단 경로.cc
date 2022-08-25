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
#include <climits>
#include <cstdlib>
#include <utility>

using namespace std;

int N, M;
int must1;
int must2;

vector<pair<int, int>> graph[200001];
int d[200001];

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;

    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(d[now] < dist) {
            continue;
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int cost =  dist + graph[now][i].second;

            if (cost < d[graph[now][i].first]) {
                d[graph[now][i].first] = cost;
                pq.push(make_pair(-cost, graph[now][i].first));
            }
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b , c});
        graph[b].push_back({a, c});
    }

    cin >> must1 >> must2;



    fill(d, d + 200001, INT_MAX);
    dijkstra(1);

    int a = d[must1];
    int b = d[must2];

    fill(d, d + 200001, INT_MAX);
    dijkstra(must1);

    int m = d[must2];

    fill(d, d + 200001, INT_MAX);
    dijkstra(N);

    int c = d[must1];
    int e = d[must2];

    int ans = min(a + m + e, b + m + c);

    if (a == INT_MAX || b == INT_MAX || c == INT_MAX || e == INT_MAX || m == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }



    return 0;
}