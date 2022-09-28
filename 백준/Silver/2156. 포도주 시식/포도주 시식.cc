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
int temp[10001];
int dp[10000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> temp[i];
    }

    dp[1] = temp[1];
    dp[2] = temp[1] + temp[2];

    for (int i = 3; i <= N; i++) {
        dp[i] = max(max(dp[i - 2] + temp[i], dp[i - 3] + temp[i - 1] + temp[i]), dp[i - 1]);
    }

    cout << dp[N];
    
    return 0;
}