#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
double len[201][201];
double dist[201][201];

double ans = DBL_MAX;

void solve(int start) {
    double tmp = 0;

    for (int from = 1; from <= N; from++) {
        for (int to = 1; to <= N; to++) {
            if (len[from][to] == -1) continue;

            double remain = len[from][to] - (dist[start][to] - dist[start][from]);

            if (remain <= 0) continue;

            tmp = max(tmp, dist[start][to] + remain / 2);
        }
    }

    ans = min(ans, tmp);
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            len[i][j] = -1;

            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 20001;
        }
    }

    for (int i = 0; i < M; i++) {
        int S, E;
        double L;
        cin >> S >> E >> L;
        len[S][E] = max(len[S][E], L);
        len[E][S] = max(len[E][S], L);
        dist[S][E] = min(dist[S][E], L);
        dist[E][S] = min(dist[E][S], L);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        solve(i);
    }

    cout << fixed;
    cout.precision(1);
    cout << ans;

    return 0;
}