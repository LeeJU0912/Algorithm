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

vector<pair<int, int>> v[10001];
int visited[10001];
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


    int a, b, c;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;

        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }

    DFS(1, 0);
    memset(visited, 0, sizeof(visited));
    maxdist = 0;
    DFS(maxnode, 0);
    cout << maxdist;

    return 0;
}