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

using namespace std;

int N;
int list[100001][3];

int minArr[3];
int maxArr[3];
int minTmp[3];
int maxTmp[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        list[i][0] = a;
        list[i][1] = b;
        list[i][2] = c;

        if (i == 0) {
            for (int j = 0; j < 3; j++) {
                minArr[j] = maxArr[j] = minTmp[j] = maxTmp[j] = list[0][j];
            }
            continue;
        }
        minArr[0] = a + min(minTmp[0], minTmp[1]);
        maxArr[0] = a + max(maxTmp[0], maxTmp[1]);

        minArr[1] = b + min({minTmp[0], minTmp[1], minTmp[2]});
        maxArr[1] = b + max({maxTmp[0], maxTmp[1], maxTmp[2]});

        minArr[2] = c + min(minTmp[1], minTmp[2]);
        maxArr[2] = c + max(maxTmp[1], maxTmp[2]);

        for (int j = 0; j < 3; j++) {
            minTmp[j] = minArr[j];
            maxTmp[j] = maxArr[j];
        }
    }

    cout << *max_element(maxArr, maxArr + 3) << ' ' << *min_element(minArr, minArr + 3);

    return 0;
}