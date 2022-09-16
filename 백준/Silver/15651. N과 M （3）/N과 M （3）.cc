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

int N, M;
int temp[7];

void dfs(int now, int counter) {
    temp[counter] = now;

    if (counter == M - 1) {
        for (int i = 0; i < M; i++) {
            cout << temp[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        dfs(i, counter + 1);
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dfs(i, 0);
    }

    return 0;
}