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

int M, N;
int ans;
int mini = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> M >> N;

    int k = 1;
    while (k * k <= N) {
        if (k * k >= M && k * k <= N) {
            ans += k * k;
            mini = min(mini, k * k);
        }
        k++;
    }

    if (ans == 0) {
        cout << -1;
        return 0;
    }
    cout << ans << '\n';
    cout << mini;

    return 0;
}