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

int D;
long long graph[8];
long long dp[8];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> D;

    dp[0] = 1;
    while (D--) {
        graph[0] = dp[1] + dp[2];
        graph[1] = dp[0] + dp[2] + dp[3];
        graph[2] = dp[0] + dp[1] + dp[3] + dp[4];
        graph[3] = dp[1] + dp[2] + dp[4] + dp[5];
        graph[4] = dp[2] + dp[3] + dp[5] + dp[6];
        graph[5] = dp[3] + dp[4] + dp[7];
        graph[6] = dp[4] + dp[7];
        graph[7] = dp[5] + dp[6];

        for (int i = 0; i < 8; i++) {
            dp[i] = graph[i] % 1000000007;
        }
    }

    cout << dp[0];

    return 0;
}