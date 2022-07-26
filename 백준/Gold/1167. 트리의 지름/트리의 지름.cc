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

using namespace std;

vector<pair<int, int>> v[100001];
int visited[100001];
int n;
int maxdist;
int maxnode;

void DFS(int start, int distance) {
    if (visited[start]) return;
    if (maxdist < distance) {
        maxdist = distance;
        maxnode = start;
    }
    visited[start] = 1;
    for (int i = 0; i < v[start].size(); i++) {
        DFS(v[start][i].first, v[start][i].second + distance);
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    int x;
    int point;

    for (int i = 1; i <= n; i++) {
        bool dist_check = false;
        cin >> x;
        int cur = x;
        while (1) {
            cin >> x;
            if (x == -1) break;
            else if (dist_check) {
                v[cur].push_back({ point, x });
                v[point].push_back({cur , x });
                dist_check = false;
            }
            else {
                point = x;
                dist_check = true;
            }
        }
    }

    DFS(1, 0);
    memset(visited, 0, sizeof(visited));
    maxdist = 0;

    DFS(maxnode, 0);
    cout << maxdist;

    return 0;
}