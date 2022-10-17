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

int n, k;
int coin[101];
int dp[10001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[k];

    return 0;
}