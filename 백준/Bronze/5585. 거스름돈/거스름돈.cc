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

int pay;
int money[6] = {500, 100, 50, 10, 5, 1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> pay;

    int charge = 1000 - pay;
    int ans = 0;

    for (int i = 0; i < 6; i++) {
        if (charge / money[i] != 0) {
            ans += charge / money[i];
            charge %= money[i];
        }
    }

    cout << ans;

    return 0;
}