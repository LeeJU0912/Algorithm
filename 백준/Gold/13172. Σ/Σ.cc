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
#include <cstdlib>
#include <utility>
#include <regex>
#include <numeric>

#define MOD 1000000007

using namespace std;

int M;
long long N[10001];
long long S[10001];
long long answer;

long long power(long long n, long long m) {
    long long ans = 1;
    while(m) {
        if (m & 1) { // m이 홀수라면 한번 더 곱해주기
            ans = ans * n % MOD;
        }
        m = m / 2; // 제곱 절반으로 줄이면서
        n = n * n % MOD; // 밑 숫자 제곱하기
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> N[i] >> S[i]; // N : 경우의 수, S : 주사위 전체 합 -> S/N 해야함
    }

    for (int i = 0; i < M; i++) {
        answer += (S[i] * (power(N[i], MOD - 2))) % MOD;
    } // S/N -> S/N^(-1) mod X = S/N^(X - 2) mod X

    cout << answer % MOD;

    return 0;
}