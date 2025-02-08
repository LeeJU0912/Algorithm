#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int a, b, c, d;

map<pair<int, int>, bool> visited;

int ans = INT_MAX;

void calc() {
    queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});
    visited[{0, 0}] = true;

    while(!pq.empty()) {
        int cnt = pq.front().first;
        int l = pq.front().second.first;
        int r = pq.front().second.second;
        pq.pop();

        if (l == c && r == d) {
            ans = min(ans, cnt);
            return;
        }

        int nextL, nextR;
        if (l != a) {
            nextL = a;
            nextR = r;
            if (!visited[{nextL, nextR}]) {
                visited[{nextL, nextR}] = true;
                pq.push({cnt + 1, {nextL, nextR}});
            }
        }
        if (l != 0) {
            nextL = 0;
            nextR = r;
            if (!visited[{nextL, nextR}]) {
                visited[{nextL, nextR}] = true;
                pq.push({cnt + 1, {nextL, nextR}});
            }
            nextL = l - min(l, (b - r));
            nextR = r + min(l, (b - r));
            if (!visited[{nextL, nextR}]) {
                visited[{nextL, nextR}] = true;
                pq.push({cnt + 1, {nextL, nextR}});
            }
        }
        if (r != b) {
            nextL = l;
            nextR = b;
            if (!visited[{nextL, nextR}]) {
                visited[{nextL, nextR}] = true;
                pq.push({cnt + 1, {nextL, nextR}});
            }
        }
        if (r != 0) {
            nextL = l;
            nextR = 0;
            if (!visited[{nextL, nextR}]) {
                visited[{nextL, nextR}] = true;
                pq.push({cnt + 1, {nextL, nextR}});
            }
            nextL = l + min(r, (a - l));
            nextR = r - min(r, (a - l));
            if (!visited[{nextL, nextR}]) {
                visited[{nextL, nextR}] = true;
                pq.push({cnt + 1, {nextL, nextR}});
            }
        }
    }
}

int main() {
    FastIO

    cin >> a >> b >> c >> d;

    calc();

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}