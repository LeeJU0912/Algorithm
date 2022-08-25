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
int from;
int to;

vector<pair<int, int>> graph[100001];
int d[100001];

void dijkstra() {
    priority_queue<pair<int, int>> pq;


    pq.push({0, from });
    d[from] = 0;

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
    }

    fill(d, d + 100001, INT_MAX);

    cin >> from >> to;

    dijkstra();

    cout << d[to];


    return 0;
}