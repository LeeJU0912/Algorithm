#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>

using namespace std;

#define MAXI 100000000

vector<pair<int, int>> v[501];

long long dist[501];
int N, M, W;
bool cycle;

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < v[j].size(); k++) {
                int next = v[j][k].first;
                int cost = v[j][k].second;

                if (dist[next] > dist[j] + cost) {
                    dist[next] = dist[j] + cost;
                    if (i == N) {
                        cycle = true;
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        cycle = false;
        fill_n(dist, 501, 0);
        for (int j = 1; j <= N; j++) {
            v[j].clear();
        }

        cin >> N >> M >> W;
        for (int j = 0; j < M; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            v[S].push_back({ E, T });
            v[E].push_back({ S, T });
        }
        for (int j = 0; j < W; j++) {
            int S, E, T;
            cin >> S >> E >> T;
            v[S].push_back({ E, -T });
        }

        solve();

        if (cycle) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}