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

int N, M;
int A, B;

vector<pair<int, int>> road[1001];
long long d[1001];
int trace[1001];

void dijkstra(int start, int end) {
    priority_queue<pair<long long, int>> pq;

    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()) {
        long long dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now] < dist) continue;
        if (start == end) break;

        for (int i = 0; i < road[now].size(); i++) {
            int next = road[now][i].first;
            long long cost = dist + road[now][i].second;
            if (cost < d[next]) {
                d[next] = cost;
                pq.push({-cost, next});
                trace[next] = now;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        road[a].push_back({b, c});
    }

    fill_n(d, 1001, LLONG_MAX);
    fill_n(trace, 1001, -1);

    cin >> A >> B;

    dijkstra(A, B);

    cout << d[B] << '\n';

    vector<int> ans1;
    int now = B;
    while(now != -1) {
        ans1.push_back(now);
        now = trace[now];
    }

    cout << ans1.size() << '\n';

    for (int i = ans1.size() - 1; i >= 0; i--) {
        cout << ans1[i] << ' ';
    }

    return 0;
}