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
vector<pair<long long, long long>> point2;

int CCW(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    long long temp = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
    temp -= (a.first * c.second) + (b.first * a.second) + (c.first * b.second);

    if (temp > 0) return 1;
    else if (!temp) return 0;
    else return -1;
}

int check2(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c) {
    if(a.first < b.first) return b.first < c.first;
    else if (b.first < a.first) return c.first < b.first;
    else {
        if (a.second < b.second) {
            return b.second < c.second;
        }
        else if (b.second < a.second) {
            return c.second < b.second;
        }
    }
}

bool check(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c, pair<long long, long long> d) {
    int ans1 = CCW(a, b, c) * CCW(a, b, d);
    int ans2 = CCW(c, d, a) * CCW(c, d, b);

    if (!ans1 && !ans2) {
        if (check2(a, b, c) && check2(a, b, d) || check2(b, a, c) && check2(b, a, d)) return false;
        else return true;
    }
    return (ans1 <= 0) && (ans2 <= 0);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 2; i++) {
        int a, b;
        cin >> a >> b;
        point.push_back({a, b});
    }
    for (int i = 0; i < 2; i++) {
        int a, b;
        cin >> a >> b;
        point2.push_back({a, b});
    }
    sort(point.begin(), point.end());
    sort(point2.begin(), point2.end());

    if (check(point[0], point[1], point2[0], point2[1])) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}