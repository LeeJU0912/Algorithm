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
int M;
int broken[10];
int ans = 1000001;

bool possible(int num) {
    if (num == 0) {
        if (broken[0] == 1) {
            return false;
        }
        else {
            return true;
        }
    }
    while (num != 0) {
        if (broken[num % 10] == 1) {
            return false;
        }
        num /= 10;
    }
    return true;
}

void solve(int current) {
    int straight = abs(N - current);
    int temp;

    for (int i = 0; i <= 1000001; i++) {
        if (possible(i)) {
            temp = to_string(i).length();
            temp += abs(i - N);
            ans = min(temp, ans);
        }
    }

    ans = min(ans, straight);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        broken[temp] = 1;
    }

    solve(100);

    cout << ans;

    return 0;
}