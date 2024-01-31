#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int dist[101][101];
vector<int> from;

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        from.clear();

        int N, M;
        cin >> N >> M;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = 1e9;
            }
        }

        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dist[a][b] = c;
            dist[b][a] = c;
        }

        int K;
        cin >> K;

        for (int i = 0; i < K; i++) {
            int a;
            cin >> a;
            from.push_back(a);
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int mini = INT_MAX;

        int ans;

        for (int i = 1; i <= N; i++) {
            int temp = 0;
            for (int j = 0; j < from.size(); j++) {
                temp += dist[from[j]][i];
            }
            if (mini > temp) {
                mini = temp;
                ans = i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}