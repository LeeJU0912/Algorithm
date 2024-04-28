#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;

vector<int> plant;
vector<pair<int, int>> graph[1001];

bool visited[1001];

int main() {
    FastIO

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        plant.push_back(temp);
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    int ans = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 0; i < K; i++) {
        visited[plant[i]] = true;
        for (int j = 0; j < graph[plant[i]].size(); j++) {
            pq.push(graph[plant[i]][j]);
        }
    }

    while(!pq.empty()) {
        int now_size = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();

        if (visited[now_node]) continue;
        visited[now_node] = true;

        ans += now_size;

        for (int i = 0; i < graph[now_node].size(); i++) {
            pq.push(graph[now_node][i]);
        }
    }
    
    cout << ans;

    return 0;
}