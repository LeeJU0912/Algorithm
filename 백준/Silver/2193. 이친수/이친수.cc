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

using namespace std;

int N;
long long dp[90][2];

void solve(int start) {
    if (start == N - 1) {
        dp[start][0] = 1;
        dp[start][1] = 1;
        return;
    }

    solve(start + 1);

    dp[start][0] = dp[start + 1][0] + dp[start + 1][1];
    dp[start][1] = dp[start + 1][0];

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;


    solve(0);

    cout << dp[0][1];

    return 0;
}