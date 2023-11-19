#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int S[20001], E[20001];
double L[20001];
double dist[201][201];

double ans = DBL_MAX;

void solve(int start) {
    double tmp = 0;

    for (int i = 0; i < M; i++) {
        tmp = max(tmp, dist[start][S[i]] + dist[start][E[i]] + L[i]);
    }

    ans = min(ans, tmp);
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = 20001;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> S[i] >> E[i] >> L[i];

        dist[S[i]][E[i]] = min(dist[S[i]][E[i]], L[i]);
        dist[E[i]][S[i]] = min(dist[E[i]][S[i]], L[i]);
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
    cout << ans / 2;

    return 0;
}