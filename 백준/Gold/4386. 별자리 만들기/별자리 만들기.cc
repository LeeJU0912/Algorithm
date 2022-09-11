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
double parent[100001];
vector<pair<double, double>> v;
vector<pair<double, pair<int, int>>> length;
double ans;

double Find(int x) {
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

double dist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(abs(p1.first - p2.first), 2) + pow(abs(p1.second - p2.second), 2));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            length.push_back({dist(v[i], v[j]), {i, j}});
        }
    }

    sort(length.begin(), length.end());

    for (int j = 0; j < length.size(); j++) {
        if (!Union(length[j].second.first, length[j].second.second)) {
            ans += length[j].first;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;

    return 0;
}