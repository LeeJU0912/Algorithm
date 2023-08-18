#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct INFO {
    int time, cost, airport;
};

struct comp {
    bool operator() (INFO a, INFO b) {
        return a.time > b.time;
    }
};

bool compare(INFO a, INFO b) {
    return a.time < b.time;
}

int N, M, K;
vector<vector<INFO>> graph;
int dist[101][10001];

int ans;

void dijkstra() {
    priority_queue<INFO, vector<INFO>, comp> pq;
    pq.push({0, 0, 1});
    dist[1][0] = 0;

    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();

        int& now_time = now.time;
        int& now_cost = now.cost;
        int& now_airport = now.airport;

        if (dist[now_airport][now_cost] < now_time) continue;

        for (int i = 0; i < graph[now_airport].size(); i++) {
            auto& next = graph[now_airport][i];
            int next_time = next.time + now_time;
            int next_cost = next.cost + now_cost;
            int& next_airport = next.airport;

            if (next_cost > M) continue;

            if (dist[next_airport][next_cost] <= next_time) continue;

            for (int j = next_cost + 1; j <= M; j++) {
                if (dist[next_airport][j] <= next_time) break;
                dist[next_airport][j] = next_time;
            }
            dist[next_airport][next_cost] = next_time;
            pq.push({next_time, next_cost, next_airport});
        }
    }
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        ans = 1e9;
        cin >> N >> M >> K;

        graph.clear();
        graph.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                dist[i][j] = 1e9;
            }
        }

        for (int i = 0; i < K; i++) {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            graph[u].push_back({d, c, v});
        }

        for (int i = 1; i <= N; i++) {
            sort(graph[i].begin(), graph[i].end(), compare);
        }
        dijkstra();

        for (int i = 0; i <= M; i++) {
            ans = min(ans, dist[N][i]);
        }

        if (ans == 1e9) {
            cout << "Poor KCM" << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}