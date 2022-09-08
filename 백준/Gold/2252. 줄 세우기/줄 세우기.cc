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

using namespace std;

int N, M;
vector<int> link[32001];
int counter[32001];
int result[32001];

void topologySort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (counter[i] == 0) {
            q.push(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        int x = q.front();
        q.pop();

        result[i] = x;

        for (int j = 0; j < link[x].size(); j++) {
            int y = link[x][j];
            if (--counter[y] == 0) {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << result[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    while (M--) {
        int a, b;
        cin >> a >> b;
        link[a].emplace_back(b);
        counter[b]++;
    }

    topologySort();

    return 0;
}