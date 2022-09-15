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

int T, N, M;

long long combination(int n, int r) {
    if (n == r || r == 0) {
        return 1;
    }
    else {
        return combination(n - 1, r - 1) + combination(n - 1, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--) {
        cin >> N >> M;

        long long ans = 1;

        int x = 1;
        for (int i = M; i > M - N; i--) {
            ans *= i;
            ans /= x++;
        }
        cout << ans << '\n';
    }

    return 0;
}