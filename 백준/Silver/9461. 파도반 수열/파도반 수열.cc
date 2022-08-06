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

long long dp[101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC;

    cin >> TC;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;

    for (int i = 0; i < TC; i++) {
        int N;
        cin >> N;

        for (int j = 5; j < N; j++) {
            if (dp[j] != 0) continue;
            dp[j] = dp[j - 5] + dp[j - 1];
        }
        cout << dp[N - 1] << '\n';
    }

    return 0;
}