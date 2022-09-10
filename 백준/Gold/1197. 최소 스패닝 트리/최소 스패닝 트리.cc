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

int V, E;
int parent[100001];
vector<pair<int, pair<int, int>>> v;
int ans;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

int Union(int x, int y) {
    int nx = Find(x);
    int ny = Find(y);
    if (nx == ny) return 1;

    parent[nx] = ny;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;

    for (int i = 1; i < V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end());

    for (int j = 0; j < v.size(); j++) {
        if (!Union(v[j].second.first, v[j].second.second)) {
            ans += v[j].first;
        }
    }

    cout << ans;

    return 0;
}