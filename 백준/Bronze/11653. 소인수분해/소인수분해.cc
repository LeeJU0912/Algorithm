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

using namespace std;

void solve(int x) {
    for (int i = 2; i <= 10000000; i++) {
        if (x == 0) return;
        while (x % i == 0) {
            x /= i;
            cout << i << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;

    cin >> N;

    solve(N);

    return 0;
}