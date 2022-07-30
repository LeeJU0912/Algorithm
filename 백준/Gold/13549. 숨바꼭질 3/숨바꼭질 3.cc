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

using namespace std;

int N, K;
int path[100001];

queue<int> q;

void bfs() {
    q.push(N);
    path[N] = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == K) return;

        if (now - 1 >= 0 && (path[now - 1] == 0 || path[now - 1] > path[now] + 1)) {
            path[now - 1] = path[now] + 1;
            q.push(now - 1);
        }
        if (now + 1 <= 100000 && (path[now + 1] == 0 || path[now + 1] > path[now] + 1)) {
            path[now + 1] = path[now] + 1;
            q.push(now + 1);
        }
        if (now * 2 <= 100000 && (path[now * 2] == 0 || path[now * 2] > path[now])) {
            path[now * 2] = path[now];
            q.push(now * 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    bfs();

    cout << path[K] - 1;


    return 0;
}