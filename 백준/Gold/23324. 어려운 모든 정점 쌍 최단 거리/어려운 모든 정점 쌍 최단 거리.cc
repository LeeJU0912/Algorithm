#include <bits/stdc++.h>
using namespace std;

int N, M, K;

vector<pair<int, int>> graph[100001];
bool visited[100001];

long long ans = -1;

int special_a;
int special_b;
bool connected;

vector<int> a_side;
vector<int> b_side;

void solve(int start) {
    if (connected) return;

    queue<int> q;
    visited[start] = true;

    for (int i = 0; i < graph[start].size(); i++) {
        if (graph[start][i].first == 1) continue;
        q.push(graph[start][i].second);
        visited[graph[start][i].second] = true;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (start == special_a) {
            a_side.push_back(now);
        }
        else {
            b_side.push_back(now);
        }

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i].second;

            if (visited[next]) continue;
            visited[next] = true;

            if (start == special_a && next == special_b) {
                ans = 0;
                connected = true;
                return;
            }

            q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (i == K - 1) {
            graph[a].emplace_back(1, b);
            graph[b].emplace_back(1, a);
            special_a = a;
            special_b = b;
        }
        else {
            graph[a].emplace_back(0, b);
            graph[b].emplace_back(0, a);
        }
    }

    solve(special_a);
    memset(visited, 0, sizeof(visited));
    solve(special_b);

    if (ans == -1) {
        cout << (a_side.size() + 1) * (b_side.size() + 1);
    }
    else {
        cout << ans;
    }


    return 0;
}