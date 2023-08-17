#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> graph[2501];
int price[2501];
long long DP[2501][2501];

void dijkstra() {
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> pq;
    pq.push({0, {price[1], 1}});

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        if (DP[now.second.second][now.second.first] != -1) continue;

        DP[now.second.second][now.second.first] = now.first;

        if (now.second.second == N) {
            cout << now.first;
            break;
        }

        for (int i = 0; i < graph[now.second.second].size(); i++) {
            auto next = graph[now.second.second][i];
            long long next_oil = min(now.second.first, price[now.second.second]);
            long long next_cost = next.first * next_oil + now.first;

            if (DP[next.second][next_oil] == -1) {
                pq.push({next_cost, {next_oil, next.second}});
            }
        }
    }


}

int main() {
    FastIO

    cin >> N >> M;

    memset(DP, -1, sizeof(DP));

    for (int i = 1; i <= N; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    dijkstra();

    return 0;
}