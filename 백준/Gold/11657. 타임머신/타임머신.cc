#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct edge {
    int start;
    int length;
    int end;
};

int N, M;
vector<edge> graph;
long long dist_to[501];

void solve() {
    dist_to[1] = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < M; j++) {
            int now = graph[j].start;
            int length = graph[j].length;
            int next = graph[j].end;

            if (dist_to[now] != LLONG_MAX && dist_to[now] + length < dist_to[next]) {
                dist_to[next] = dist_to[now] + length;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        int now = graph[j].start;
        int length = graph[j].length;
        int next = graph[j].end;

        if (dist_to[now] != LLONG_MAX && dist_to[now] + length < dist_to[next]) {
            cout << -1;
            return;
        }
    }

    for (int i = 2; i <= N; i++) {
        if (dist_to[i] == LLONG_MAX) {
            cout << -1 << '\n';
        }
        else {
            cout << dist_to[i] << '\n';
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dist_to[i] = LLONG_MAX;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph.push_back({a, c, b});
    }

    solve();

    return 0;
}