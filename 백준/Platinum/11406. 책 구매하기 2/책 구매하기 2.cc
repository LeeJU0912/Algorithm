#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int capacity[202][202];
int flow[202][202];

int ans;

void solve(int source, int sink) {

    while(true) {
        int parent[202];
        memset(parent, -1, sizeof(parent));

        queue<int> q;
        q.push(source);

        while(!q.empty() && parent[sink] == -1) {
            int now = q.front();
            q.pop();

            for (int i = 0; i <= 201; i++) {
                int next = i;

                if (capacity[now][next] - flow[now][next] <= 0) continue;
                if (parent[next] != -1) continue;

                q.push(next);
                parent[next] = now;

                if (next == sink) break;
            }
        }

        if (parent[sink] == -1) break;

        int mini = INT_MAX;
        for (int i = sink; i != source; i = parent[i]) {
            mini = min(mini, capacity[parent[i]][i] - flow[parent[i]][i]);
        }
        for (int i = sink; i != source; i = parent[i]) {
            flow[parent[i]][i] += mini;
            flow[i][parent[i]] -= mini;
        }

        ans += mini;
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> capacity[0][i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> capacity[i + 100][201];
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> capacity[j][i + 100];
        }
    }

    solve(0, 201);

    cout << ans;

    return 0;
}