#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> graph[100001];
int parent[100001];
bool visited[100001];

void solve(int idx) {
    visited[idx] = true;
    for (int i = 0; i < graph[idx].size(); i++) {
        int next = graph[idx][i];

        if (visited[next]) continue;

        parent[next] = idx;
        solve(next);
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1);

    for (int i = 2; i <= N; i++) {
        cout << parent[i] << '\n';
    }

    return 0;
}