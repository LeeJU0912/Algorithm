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

int N, M;
int sum;
int memory[101];
int cost[101];
int cache[101][10001];
int ans = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> memory[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j - cost[i] >= 0) {
                cache[i][j] = max(cache[i][j], cache[i - 1][j - cost[i]] + memory[i]);
            }
            cache[i][j] = max(cache[i][j], cache[i - 1][j]);

            if (cache[i][j] >= M) {
                ans = min(ans, j);
            }
        }
    }

    cout << ans;

    return 0;
}