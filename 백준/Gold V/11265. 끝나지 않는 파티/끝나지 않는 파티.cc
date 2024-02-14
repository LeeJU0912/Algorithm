#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int dist[501][501];

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            dist[i][j] = temp;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        if (dist[A - 1][B - 1] <= C) {
            cout << "Enjoy other party" << '\n';
        }
        else {
            cout << "Stay here" << '\n';
        }
    }

    return 0;
}