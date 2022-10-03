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

int N, M, R;
vector<int> v[100001];
int visited[100001];
int ans[100001];
int counter = 1;

void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        ans[now] = counter++;

        sort(v[now].begin(), v[now].end());

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (visited[next]) continue;
            visited[next] = 1;
            q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> R;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bfs(R);

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}