#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<pair<int, int>> graph[10001];
int DP[10001];

int main() {
    FastIO


    int N, D;
    cin >> N >> D;

    for (int i = 0; i <= D; i++) {
        DP[i] = INT_MAX;
    }

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    DP[0] = 0;
    for (int i = 0; i <= D; i++) {
        if (i > 0) {
            DP[i] = min(DP[i], DP[i - 1] + 1);
        }
        if (!graph[i].empty()) {
            for (int j = 0; j < graph[i].size(); j++) {
                DP[graph[i][j].second] = min(DP[graph[i][j].second], DP[i] + graph[i][j].first);
            }
        }

    }
    
    cout << DP[D];

    return 0;
}