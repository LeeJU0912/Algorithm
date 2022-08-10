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

int T, K;
int book[501];
int hap[501];
int DP[501][501];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int test = 0; test < T; test++) {
        cin >> K;
        for (int i = 1; i <= K; i++) {
            cin >> book[i];
            hap[i] = hap[i - 1] + book[i];
        }
        for (int i = 1; i < K; i++) { // 구간 범위의 크기 (i 사이의 값)
            for (int j = 1; i + j <= K; j++) { // 구간의 시작점
                DP[j][i + j] = INT_MAX;
                for (int k = j; k <= i + j; k++) { // 구간을 반으로 나누는 부분
                    DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + hap[i + j] - hap[j - 1]);
                }
            }
        }

        cout << DP[1][K] << '\n';
    }

    return 0;
}