#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
int graph[101][101];
int road[101][101];

vector<int> path;

void findPath(int start, int end) {
    int before = road[start][end];
    if (start == before) {
        path.push_back(before);
    }
    else {
        findPath(start, before);
        findPath(before, end);
    }
}

int main() {
    FastIO

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 100000000;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a][b] = min(graph[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            road[i][j] = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (j == k) {
                    graph[j][k] = 0;
                }
                else if (graph[j][k] > graph[j][i] + graph[i][k]) {
                    graph[j][k] = graph[j][i] + graph[i][k];

                    road[j][k] = i;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] == 100000000) {
                cout << 0 << ' ';
            }
            else {
                cout << graph[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    for (int start = 1; start <= n; start++) {
        for (int end = 1; end <= n; end++) {
            if (graph[start][end] == 100000000 || graph[start][end] == 0) {
                cout << 0;
            }
            else {
                path.clear();
                findPath(start, end);
                cout << path.size() + 1 << ' ';
                for (auto i : path) {
                    cout << i << ' ';
                }
                cout << end;
            }
            cout << '\n';
        }
    }

    return 0;
}