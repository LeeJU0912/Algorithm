#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
vector<int> candy;
vector<int> graph[30001];
bool visited[30001];

vector<pair<int, int>> save;

int DP[30001][3001];

void solve(int start) {
    int candy_sum = 0;
    int people_sum = 0;
    visited[start] = true;

    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        candy_sum += candy[now];
        people_sum++;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (visited[next]) continue;
            visited[next] = true;

            q.push(next);
        }
    }

    save.push_back({candy_sum, people_sum});
}

int main() {
    FastIO

    cin >> N >> M >> K;

    candy = vector<int>(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> candy[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        solve(i);
    }

    for (int i = 1; i <= save.size(); i++) {
        for (int j = 1; j < K; j++) {
            int weight = save[i - 1].second;
            int val = save[i - 1].first;

            if (weight <= j) {
                DP[i][j] = max(DP[i - 1][j - weight] + val, DP[i - 1][j]);
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    cout << DP[save.size()][K - 1];

    return 0;
}