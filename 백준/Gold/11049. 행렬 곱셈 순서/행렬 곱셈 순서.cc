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

int N;
int sero[501];
int garo[501];

int DP[501][501];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> sero[i] >> garo[i];
    }

    for (int i = 1; i < N; i++) { // 구간 범위의 크기 (i 사이의 값)
        for (int j = 1; i + j <= N; j++) { // 구간의 시작점
            DP[j][i + j] = INT_MAX;
            for (int k = j; k <= i + j; k++) { // 구간을 반으로 나누는 부분
                DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + sero[j] * garo[k] * garo[i + j]);
                // 최솟값(계산 안한 값이 0이면 무조건 최소이므로 j~i+j 설정, j~k 구간 최소값 + k+1~i+j 구간 최소값 + [i~i+j구간 구하기]구간 시작 * k로 나뉘는 부분 * 구간 끝)
            }
        }
    }

    cout << DP[1][N];

    return 0;
}