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

vector<pair<long long, long long>> point;

int CCW(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    long long temp = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
    temp -= (a.first * c.second) + (b.first * a.second) + (c.first * b.second);

    if (temp > 0) return 1;
    else if (!temp) return 0;
    else return -1;
}

bool check(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d) {
    int ans1 = CCW(a, b, c) * CCW(a, b, d);
    int ans2 = CCW(c, d, a) * CCW(c, d, b);

    return (ans1 < 0) && (ans2 < 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 4; i++) {
        int a, b;
        cin >> a >> b;
        point.push_back({a, b});
    }

    if (check(point[0], point[1], point[2], point[3])) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}