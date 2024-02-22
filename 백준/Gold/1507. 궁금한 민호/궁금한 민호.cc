#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int shortest[21][21];
int dist[21][21];

vector<pair<int, pair<int, int>>> road;

void init_dist() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 1e9;
        }
    }
}

bool chk_same() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dist[i][j] != shortest[i][j]) return false;
        }
    }
    return true;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> shortest[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            road.push_back({shortest[i][j], {i, j}});
        }
    }

    sort(road.begin(), road.end());

    int ans = 0;
    for (int t = 0; t < road.size(); t++) {
        int x = road[t].second.first;
        int y = road[t].second.second;
        int d = road[t].first;

        if (dist[x][y] == d) continue;

        init_dist();

        for (int z = 0; z < t; z++) {
            int x2 = road[z].second.first;
            int y2 = road[z].second.second;
            int d2 = road[z].first;
            dist[x2][y2] = d2;
            dist[y2][x2] = d2;
        }

        ans += d;

        dist[x][y] = d;
        dist[y][x] = d;

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        if (!chk_same()) continue;
        cout << ans;
        return 0;
    }

    cout << -1;

    return 0;
}