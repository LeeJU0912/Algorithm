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

int N;
int parent[100001];
vector<pair<int, int>> x;
vector<pair<int, int>> y;
vector<pair<int, int>> z;

vector<pair<int, pair<int, int>>> length;
int ans;

int Find(int temp) {
    if (parent[temp] == temp) return temp;
    return parent[temp] = Find(parent[temp]);
}

int Union(int dx, int dy) {
    int nx = Find(dx);
    int ny = Find(dy);
    if (nx == ny) return 1;

    parent[nx] = ny;
    return 0;
}

int dist(tuple<int, int, int> p1, tuple<int, int, int> p2) {
    return min(abs(get<0>(p1) - get<0>(p2)), min(abs(get<1>(p1) - get<1>(p2)), abs(get<2>(p1) - get<2>(p2))));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x.push_back({a, i});
        y.push_back({b, i});
        z.push_back({c, i});
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 0; i < N - 1; i++) {
        length.push_back({x[i + 1].first - x[i].first, {x[i].second, x[i + 1].second}});
        length.push_back({y[i + 1].first - y[i].first, {y[i].second, y[i + 1].second}});
        length.push_back({z[i + 1].first - z[i].first, {z[i].second, z[i + 1].second}});
    }

    sort(length.begin(), length.end());

    for (int j = 0; j < length.size(); j++) {
        if (!Union(length[j].second.first, length[j].second.second)) {
            ans += length[j].first;
        }
    }

    cout << ans;

    return 0;
}