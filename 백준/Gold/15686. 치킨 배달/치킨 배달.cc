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

using namespace std;

int N, M;
int city[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
int visited[13];
int result = INT_MAX;

int distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int idx, int counter) {
    if (counter == M) {
        int temp = 0;
        for (int i = 0; i < house.size(); i++) {
            int dist = INT_MAX;
            for (int j = 0; j < chicken.size(); j++) {
                if (visited[j]) {
                    dist = min(dist, distance(house[i], chicken[j]));
                }
            }
            temp += dist;
        }
        result = min(result, temp);
        return;
    }

    if (idx == chicken.size()) {
        return;
    }

    visited[idx] = true;
    solve(idx + 1, counter + 1);
    visited[idx] = false;
    solve(idx + 1, counter);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];
            if (city[i][j] == 1) {
                house.push_back({i , j});
            }
            else if (city[i][j] == 2) {
                chicken.push_back({i , j});
            }
        }
    }

    solve(0, 0);

    cout << result;

    return 0;
}