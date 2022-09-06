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

using namespace std;

long long a, b, c;

long long solve(long long n, long long m) {
    long long ans = 1;
    while(m) {
        if (m % 2 == 1) {
            ans = ans * n % c;
        }
        m = m / 2;
        n = n * n % c;
    }
    return ans % c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> a >> b >> c;

    cout << solve(a, b);

    return 0;
}