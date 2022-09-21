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
int A[12];
int calc[4];
int mini = INT_MAX;
int maxi = INT_MIN;

void solve(int sum, int i, int a, int b, int c, int d) {
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        mini = min(mini, sum);
        maxi = max(maxi, sum);
        return;
    }

    if (a > 0) {
        solve(sum + A[i], i + 1, a - 1, b, c, d);
    }
    if (b > 0) {
        solve(sum - A[i], i + 1, a, b - 1, c, d);
    }
    if (c > 0) {
        solve(sum * A[i], i + 1, a, b, c - 1, d);
    }
    if (d > 0) {
        solve(sum / A[i], i + 1, a, b, c, d - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++) {
        int temp;
        cin >> temp;
        calc[i] = temp;
    }

    solve(A[0], 1, calc[0], calc[1], calc[2], calc[3]);

    cout << maxi << '\n' << mini;

    return 0;
}