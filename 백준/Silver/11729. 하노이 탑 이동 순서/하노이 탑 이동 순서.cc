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

int N;

void hanoi(int n, int start, int to, int temp) { // N번째 원판을 3번째로 옮기려면 N-1번째 원판은 반드시 2번째로 옮겨야 한다.
    if (n == 1) cout << start << ' ' << to << '\n';
    else {
        hanoi(n - 1, start, temp, to); // N - 1개를 2번 막대기로 옮겨놓고
        cout << start << ' ' << to << '\n';
        hanoi(n - 1, temp, to, start); // N번째 원판을 3번 막대기로 옮긴다
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    cout << (1 << N) - 1 << '\n';

    hanoi(N, 1, 3, 2);

    return 0;
}