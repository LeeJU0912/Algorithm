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

int N, R, Q;
vector<int> connect[100001];
int visited[100001];
int ans[100001];

int dfs(int root) {
    if (ans[root] != 0) return ans[root];
    visited[root] = 1;
    int ret = 1;
    for (int i = 0; i < connect[root].size(); i++) {
        int next = connect[root][i];
        if (!visited[next]) {
            ret += dfs(next);
        }
    }
    ans[root] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    ans[R] = dfs(R);
    for (int i = 0; i < Q; i++) {
        int a;
        cin >> a;
        cout << ans[a] << '\n';
    }

    return 0;
}