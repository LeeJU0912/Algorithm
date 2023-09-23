#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[10001];
int save[10001];
bool visited[10001];

void counter(int x) {
    if (visited[x]) return;
    visited[x] = true;

    save[x]++;

    for (int i = 0; i < graph[x].size(); i++) {
        counter(graph[x][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
    }

    for (int i = 1; i <= N; i++) {
        counter(i);
        memset(visited, false, sizeof(visited));
    }

    int maxi = 0;
    for (int i = 1; i <= N; i++) {
        maxi = max(maxi, save[i]);
    }

    for (int i = 1; i <= N; i++) {
        if (save[i] == maxi) {
            cout << i << ' ';
        }
    }

    return 0;
}