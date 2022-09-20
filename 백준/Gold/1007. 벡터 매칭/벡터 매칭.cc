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

int T, N;

pair<int, int> p[21];
double ans;
int visited[21];

double length() {
    pair<int, int> a = {0, 0};
    pair<int, int> b = {0, 0};

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            a.first += p[i].first;
            a.second += p[i].second;
        }
        else {
            b.first += p[i].first;
            b.second += p[i].second;
        }
    }

    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

void dfs(int remain, int start) {
    if (remain == 0) {
        double len = length();

        if (ans > len) {
            ans = len;
        }
    }
    else {
        for (int i = start; i < N; i++) {
            if (!visited[i]) {
                visited[i] = 1;
                dfs(remain - 1, i);
                visited[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--) {

        cin >> N;

        ans = DBL_MAX;
        fill(visited, visited + N, 0);

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> p[i].first >> p[i].second;
        }
        dfs(N / 2, 0);

        cout << fixed;
        cout.precision(7);
        cout << ans << '\n';
    }

    return 0;
}