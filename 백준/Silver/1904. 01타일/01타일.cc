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

int dp[1000000][3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;
    
    dp[0][0] = 1;
    dp[0][2] = 1;
    
    for (int i = 1; i < N; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % 15746;
        dp[i][1] = dp[i - 1][0] % 15746;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][2]) % 15746;
    }

    cout << (dp[N - 1][2] + dp[N - 1][1]) % 15746;

    return 0;
}