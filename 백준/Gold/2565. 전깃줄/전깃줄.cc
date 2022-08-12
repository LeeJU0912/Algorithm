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

using namespace std;

int N;

int B[501];
vector<int>v;
int dp[501];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    pair<int, int >vp[101];
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> vp[i].first >> vp[i].second;
    sort(vp, vp + n);
    int res = -1;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (vp[j].second < vp[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout << n- res << '\n';

    return 0;
}