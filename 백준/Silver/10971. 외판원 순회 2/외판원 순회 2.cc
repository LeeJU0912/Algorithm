#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<pair<int, int>> road[10];
bool visited[10];

int startPoint;

int ans = INT_MAX;

void go(int start, int sum, int counter) {
    if (counter == N) {
        for (int i = 0; i < road[start].size(); i++) {
            int next = road[start][i].second;
            int next_length = road[start][i].first;

            if (next == startPoint) {
                ans = min(ans, sum + next_length);
                return;
            }
        }
    }

    visited[start] = true;
    for (int i = 0; i < road[start].size(); i++) {
        int next = road[start][i].second;
        int next_length = road[start][i].first;

        if (visited[next]) continue;
        go(next, sum + next_length, counter + 1);
    }
    visited[start] = false;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;

            if (temp == 0) continue;

            road[i].push_back({temp, j});
        }
    }

    for (int i = 0; i < N; i++) {
        startPoint = i;
        go(i, 0, 1);
    }

    cout << ans;

    return 0;
}