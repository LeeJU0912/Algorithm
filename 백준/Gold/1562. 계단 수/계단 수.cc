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
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

#define MOD 1000000000

int N;
long long ans;
int dp[101][10][1 << 10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    for (int length = 2; length <= N; length++) {
        for (int i = 0; i <= 9; i++) {
            for (int bit = 0; bit < (1 << 10); bit++) {
                int offset = bit | (1 << i);

                if (i == 0) {
                    dp[length][i][offset] = (dp[length][i][offset] + dp[length - 1][i + 1][bit]) % MOD;
                }
                else if (i == 9) {
                    dp[length][i][offset] = (dp[length][i][offset] + dp[length - 1][i - 1][bit]) % MOD;
                }
                else {
                    dp[length][i][offset] = (dp[length][i][offset] + dp[length - 1][i + 1][bit]) % MOD;
                    dp[length][i][offset] = (dp[length][i][offset] + dp[length - 1][i - 1][bit]) % MOD;
                }
            }
        }
    }

    for (int i = 0; i <= 9; i++) {
        ans = (ans + dp[N][i][1023]) % MOD;
    }

    cout << ans;

    return 0;
}