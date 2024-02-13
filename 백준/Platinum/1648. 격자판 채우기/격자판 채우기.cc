#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 9901

int N, M;

int DP[(1 << 15)][15];

long long solve(int idx, int now_m, int now_bit, int before_bit) {
    if (idx > N) return 0;
    if (idx == N) return DP[before_bit][now_m - 1];

    // 현재 Bit에 맞는 직전 열 Bit 정보 짜맞추기
    // 현재 행 위치가 1인 경우
    if (now_bit & (1 << idx)) {
        long long ans = solve(idx + 1, now_m, now_bit, before_bit);
        // 지금 행의 양옆이 붙어 있는 경우
        if (now_bit & (1 << (idx + 1)) && (idx + 1 < N)) {
            // 이전 행의 같은 위치도 1로 만든다.
            ans += solve(idx + 2, now_m, now_bit, before_bit | (1 << idx) | (1 << (idx + 1)));
        }
        ans %= MOD;
        return ans;
    }
    // 현재 행 위치가 0인 경우
    // 직전 열에 지금 행 대로 채운다.
    else return solve(idx + 1, now_m, now_bit, before_bit | (1 << idx));
}

int main() {
    FastIO

    cin >> N >> M;

    if ((N * M) % 2) {
        cout << 0;
        return 0;
    }

    if (N > M) swap(N, M);

    // 초기값 설정
    DP[(1 << N) - 1][0] = 1;

    // DP[현재 Bit][현재 열] = 이전 Bit 정보들을 사용하여 구하기
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < (1 << N); j++) {
            DP[j][i] = solve(0, i, j, 0);
        }
    }

    cout << DP[((1 << N) - 1)][M];

    return 0;
}