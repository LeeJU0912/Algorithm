#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;

int counter[2001][2001][2];

int ans = INT_MAX;

int main() {
    FastIO

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        for (int j = 1; j <= M; j++) {
            counter[i][j][0] = counter[i - 1][j][0];
            counter[i][j][1] = counter[i - 1][j][1];
            if ((i + j) % 2 == 0) {
                if (s[j - 1] == 'B') {
                    counter[i][j][0]++;
                }
            }
            else {
                if (s[j - 1] == 'W') {
                    counter[i][j][1]++;
                }
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            counter[j][i][0] += counter[j][i - 1][0];
            counter[j][i][1] += counter[j][i - 1][1];
        }
    }

    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            int now_black = counter[i][j][0] - counter[i - K][j][0] - counter[i][j - K][0] + counter[i - K][j - K][0];
            int now_white = counter[i][j][1] - counter[i - K][j][1] - counter[i][j - K][1] + counter[i - K][j - K][1];
            int max_w, max_b;

            if (K % 2) {
                max_w = K * K / 2;
                max_b = K * K - max_w;
            }
            else {
                max_w = K * K / 2;
                max_b = K * K / 2;
            }

            ans = min(ans, min((max_b - now_black) + (max_w - now_white), now_black + now_white));
        }
    }

    cout << ans;

    return 0;
}