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

vector<pair<int, int>> point1[3000];
vector<int> connect[3000];
int parent[3000];
int visited[3000];
int ans, group;

int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int temp = (a.first * b.second) + (b.first * c.second) + (c.first * a.second);
    temp -= (a.first * c.second) + (b.first * a.second) + (c.first * b.second);

    if (temp > 0) return 1;
    else if (!temp) return 0;
    else return -1;
}

int check2(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
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

bool check(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    int ans1 = CCW(a, b, c) * CCW(a, b, d);
    int ans2 = CCW(c, d, a) * CCW(c, d, b);

    if (!ans1 && !ans2) {
        if (check2(a, b, c) && check2(a, b, d) || check2(b, a, c) && check2(b, a, d)) return false;
        else return true;
    }
    return (ans1 <= 0) && (ans2 <= 0);
}

int get_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = get_parent(parent[x]);
}

void Union(int x, int y) {
    int px = get_parent(x);
    int py = get_parent(y);

    if (px == py) return;
    else {
        parent[px] = py;
        connect[px].push_back(py);
        connect[py].push_back(px);
    }
}

int dfs(int start) {
    visited[start] = 1;
    int temp = 1;

    for (int i = 0; i < connect[start].size(); i++) {
        int next = connect[start][i];

        if(!visited[next]) {
            temp += dfs(next);
        }
    }
    ans = max(ans, temp);
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    int a, b;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a >> b;
            point1[i].push_back({a, b});
        }
    }

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (check(point1[i][0], point1[i][1], point1[j][0], point1[j][1])){
                Union(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            group++;
            dfs(i);
        }
    }

    cout << group << '\n' << ans;

    return 0;
}