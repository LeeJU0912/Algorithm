#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<pair<int, int>> save;
vector<int> P, R;

int range;

int dist[3001][3001];
bool visited[3001];

queue<int> startPoint;

int ans;

void getDist(int a, int b) {
    int tmp = (save[a].first - save[b].first) * (save[a].first - save[b].first)
            + (save[a].second - save[b].second) * (save[a].second - save[b].second);
    dist[a][b] = tmp;
    dist[b][a] = tmp;
}

void bfs() {

    while(!startPoint.empty()) {
        int now = startPoint.front();
        startPoint.pop();

        ans++;

        for (int i = 0; i < N; i++) {
            int next = i;

            if (visited[next]) continue;
            if (dist[now][next] > range) continue;
            visited[next] = true;

            startPoint.push(next);
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;

        save.push_back({X, Y});
    }

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        x--;
        P.push_back(x);
    }

    cin >> range;
    range *= range;

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        R.push_back(x * x);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == P[j]) continue;
            getDist(i, P[j]);
        }
    }

    for (int i = 0; i < N; i++) {
        bool canGo = true;

        for (int j = 0; j < M; j++) {
            if (dist[i][P[j]] <= R[j]) {
                canGo = false;
                break;
            }
        }

        if (canGo) {
            startPoint.push(i);
            visited[i] = true;
        }
    }

    bfs();

    cout << ans;
    
    return 0;
}