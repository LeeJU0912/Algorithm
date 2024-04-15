#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, A, B;
vector<pair<int, int>> graph[100001];
int dist[100001];
int longest[100001];

int ans;

void dijkstra() {
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<>> pq;
    pq.push({{0, 0}, A});
    dist[A] = 0;

    while(!pq.empty()) {
        int now_hap = pq.top().first.first;
        int now_longest = pq.top().first.second;
        int now_node = pq.top().second;
        pq.pop();

        if (now_node == B) {
            ans = now_hap - now_longest;
            return;
        }

        for (int i = 0; i < graph[now_node].size(); i++) {
            int next_node = graph[now_node][i].second;
            int next_size = graph[now_node][i].first;

            if (now_hap + next_size > dist[next_node]) continue;
            else if (now_hap + next_size == dist[next_node]) {
                if (longest[next_node] >= now_longest) continue;
            }
            
            dist[next_node] = now_hap + next_size;
            longest[next_node] = max(next_size, now_longest);

            pq.push({{now_hap + next_size, max(now_longest, next_size)}, next_node});
        }
    }
}

int main() {
    FastIO

    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++) {
        dist[i] = 1e9;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    dijkstra();

    cout << ans;

    return 0;
}