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
vector<int> go[32001];
int counter[32001];

void solve() {
    priority_queue<int, vector<int>, greater<>> pq;

    for (int i = 1; i <= N; i++) {
        if (counter[i] == 0) pq.push(i);
    }

    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();

        cout << now << ' ';

        for (int i = 0; i < go[now].size(); i++) {
            int next = go[now][i];
            if (--counter[next] == 0) pq.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    while(M--) {
        int a, b;
        cin >> a >> b;
        go[a].push_back(b);
        counter[b]++;
    }

    solve();

    return 0;
}