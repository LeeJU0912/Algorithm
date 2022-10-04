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

int N;
int dp[10][101];
//
//int stairNum(int start, int length) {
//    if (start < 0 || start > 9) return 0;
//    int& result = dp[start][length];
//    if (result != -1) {
//        return result;
//    }
//    return result = (stairNum(start - 1, length - 1) + stairNum(start + 1, length - 1)) % 1000000000;
//}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i < 10; i++) {
        dp[i][1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[0][i] = dp[j + 1][i - 1];
            }
            else if (j == 9) {
                dp[9][i] = dp[j - 1][i - 1];
            }
            else {
                dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
            }

            dp[j][i] %= 1000000000;
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[i][N];
        ans %= 1000000000;
    }

    cout << ans;

    return 0;
}