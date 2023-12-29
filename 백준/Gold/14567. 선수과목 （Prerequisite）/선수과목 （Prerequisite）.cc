#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<int> graph[1001];
int counter[1001];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    counter[start] = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];

            if (counter[next] >= counter[now] + 1) continue;

            counter[next] = counter[now] + 1;

            q.push(next);
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        if (counter[i]) continue;
        bfs(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << counter[i] << ' ';
    }

    return 0;
}