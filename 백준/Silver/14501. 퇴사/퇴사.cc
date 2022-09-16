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
int T[16];
int P[16];
int dp[16];
int ans;

void solve(int start, int sum) {
    int next = start + T[start];

    if (start == N || next > N) {
        ans = max(ans, sum);
        return;
    }
    else {
        for (int i = next; i <= N; i++) {
            if (i + T[i] - 1 <= N) {
                solve(i, sum + P[i]);
            }
        }
    }
    ans = max(ans, sum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        T[i] = a;
        P[i] = b;
    }

    for (int i = 1; i <= N; i++) {
        if (i + T[i] - 1 > N) continue;
        solve(i, P[i]);
    }

    cout << ans;

    return 0;
}