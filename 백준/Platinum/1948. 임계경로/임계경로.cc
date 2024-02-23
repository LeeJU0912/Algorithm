#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
vector<pair<int, int>> graph[10001];
vector<pair<int, int>> graph_reverse[10001];
int indegree[10001];
int max_node_time[10001];
bool visited[10001];

int dept, dest;

int node_count;

void find_max_time() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, dept});

    indegree[dept] = 1;

    while(!pq.empty()) {
        int now_time = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        indegree[now_node]--;
        if (indegree[now_node]) continue;
        max_node_time[now_node] = now_time;

        if (now_node == dest) {
            continue;
        }

        for (int i = 0; i < graph[now_node].size(); i++) {
            int next_node = graph[now_node][i].second;
            int dist = graph[now_node][i].first;

            pq.push({now_time + dist, next_node});
        }
    }
}

void find_road() {
    queue<pair<int, int>> q;
    q.push({0, dest});

    while(!q.empty()) {
        int now_time = q.front().first;
        int now_node = q.front().second;
        q.pop();

        if (now_node == dept) {
            continue;
        }

        for (int i = 0; i < graph_reverse[now_node].size(); i++) {
            int next_node = graph_reverse[now_node][i].second;
            int dist = graph_reverse[now_node][i].first;


            if (max_node_time[next_node] + now_time + dist != max_node_time[dest]) continue;
            if (visited[next_node]) {
                node_count++;
                continue;
            }
            visited[next_node] = true;

            q.push({now_time + dist, next_node});
            node_count++;
        }
    }
}

int main() {
    FastIO

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph_reverse[b].push_back({c, a});
        indegree[b]++;
    }

    cin >> dept >> dest;

    find_max_time();
    cout << max_node_time[dest] << '\n';

    find_road();
    cout << node_count;

    return 0;
}