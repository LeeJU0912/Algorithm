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
#include <list>

using namespace std;

int N, M;
int ans;

void solve(int x, int y, int lx, int ly, int counter) {
    if (lx == 1 && ly == 1) {
//        ans += counter;
        return;
    }

    ans++;

    if (lx >= ly) {
        if (lx % 2 == 1) {
            solve(x - lx + 1, y, 1, ly, counter + 1);
            solve(x, y, lx - 1, ly, counter + 1);
        }
        else {
            solve(x - lx / 2, y, lx / 2, ly, counter + 1);
            solve(x, y, lx / 2, ly, counter + 1);
        }


    }
    else {
        if (ly % 2 == 1) {
            solve(x, y - ly + 1, lx, 1, counter + 1);
            solve(x, y, lx, ly - 1, counter + 1);
        }
        else {
            solve(x, y - lx / 2, lx, ly / 2, counter + 1);
            solve(x, y, lx, ly / 2, counter + 1);
        }

    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    solve(N, M, N, M, 0);

    cout << ans;

    return 0;
}