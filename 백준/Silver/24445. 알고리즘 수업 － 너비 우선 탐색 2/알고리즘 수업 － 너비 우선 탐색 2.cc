#include <bits/stdc++.h>

using namespace std;

int N, M, R;

vector<int> v[100001];
bool visited[100001];
queue<int> q;

int ans[100001];

void bfs() {
    visited[R] = true;
    q.push(R);
    int counter = 0;

    while(!q.empty()) {
        int next = q.front();
        q.pop();
        counter++;
        ans[next] = counter;
        sort(v[next].begin(), v[next].end(), greater<>());

        for (int i = 0; i < v[next].size(); i++) {
            if (!visited[v[next][i]]) {
                visited[v[next][i]] = true;
                q.push(v[next][i]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs();

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}