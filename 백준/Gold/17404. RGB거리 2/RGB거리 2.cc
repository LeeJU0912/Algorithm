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

int N;
int house[1001][3];
int cost[1001][3];
int ans = 10000000;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for (int start = 0; start <= 2; start++) {
        for (int i = 0; i <= 2; i++) {
            if (i == start) {
                house[1][i] = cost[1][i];
            }
            else {
                house[1][i] = 100000000;
            }
        }

        for (int i = 2; i <= N; i++) {
            house[i][0] = min(house[i - 1][1], house[i - 1][2]) + cost[i][0];
            house[i][1] = min(house[i - 1][0], house[i - 1][2]) + cost[i][1];
            house[i][2] = min(house[i - 1][0], house[i - 1][1]) + cost[i][2];
        }

        for (int i = 0; i <= 2; i++) {
            if (i == start) continue;
            else ans = min(ans, house[N][i]);
        }
    }

    cout << ans;

    return 0;
}