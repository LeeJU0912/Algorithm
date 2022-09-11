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
int Number[100000];
int ans = -1000;
int MaxNum[100000];

void dfs(int start) {
    if (start == N) return;

    if (start == 0) {
        MaxNum[0] = Number[0];
    }
    else {
        MaxNum[start] = max(MaxNum[start - 1] + Number[start], Number[start]);
    }

    dfs(start + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> Number[i];
    }

    memset(MaxNum, -1001, sizeof(MaxNum));

    dfs(0);

    cout << *max_element(MaxNum, MaxNum + N);

    return 0;
}