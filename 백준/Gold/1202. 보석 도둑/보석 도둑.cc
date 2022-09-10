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

int N, K;
vector<pair<int, int>> v;
priority_queue<int> pq;
int bag_size[300001];
long long answer;

void solve() {
    sort(bag_size, bag_size + K);
    sort(v.begin(), v.end());

    int idx = 0;
    for (int i = 0; i < K; i++) {
        while (idx < N && v[idx].first <= bag_size[i])
            pq.push(v[idx++].second);
        if (!pq.empty()) {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 0; i < K; i++) {
        cin >> bag_size[i];
    }

    solve();

    return 0;
}