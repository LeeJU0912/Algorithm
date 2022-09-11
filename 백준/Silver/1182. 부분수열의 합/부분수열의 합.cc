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

int N, S;
int Number[20];
int counter;

void dfs(int start, int sum) {
    sum += Number[start];
    if (sum == S) {
        counter++;
    }

    for (int i = start + 1; i < N; i++) {
        dfs(i, sum);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> Number[i];
    }

    for (int i = 0; i < N; i++) {
        dfs(i, 0);
    }


    cout << counter;

    return 0;
}