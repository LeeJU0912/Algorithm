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

int n;
int dp[100001];
int low = 100000;

void solve() {
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (dp[i - j * j] < low) {
                low = dp[i - j * j];
            }
        }
        dp[i] = low + 1;
        low = 100000;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    solve();

    cout << dp[n];

    return 0;
}