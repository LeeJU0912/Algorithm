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

using namespace std;

long long A, B;
long long d[55];

long long num (long long x, long long i = 54) {
    long long ans = x & 1;
    for (; i > 0; i--) {
        if (x & (1LL << i)) {
            ans += d[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> A >> B;

    d[0] = 1;
    for (long long i = 1; i < 55; i++) {
        d[i] = d[i - 1] * 2 + (1LL << i);
    }

    cout << num(B) - num(A - 1);

    return 0;
}