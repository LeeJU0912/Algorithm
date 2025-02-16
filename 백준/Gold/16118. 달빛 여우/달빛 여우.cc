#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<pair<int, int>> graph[4001];
int distFox[4001];
int distWolf[4001][2];

void solveFox() {
    queue<pair<int, int>> q;

    q.push({0, 1});
    distFox[1] = 0;

    while(!q.empty()) {
        int nowNode = q.front().second;
        q.pop();

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextDist = graph[nowNode][i].first;
            int nextNode = graph[nowNode][i].second;

            if (distFox[nextNode] <= distFox[nowNode] + nextDist) continue;
            distFox[nextNode] = distFox[nowNode] + nextDist;

            q.push({distFox[nextNode], nextNode});
        }
    }
}

void solveWolf() {
    queue<pair<int, pair<bool, int>>> q;

    q.push({0, {false, 1}});
    distWolf[1][0] = 0;

    while(!q.empty()) {
        bool isTired = q.front().second.first;
        int nowNode = q.front().second.second;
        q.pop();

        for (int i = 0; i < graph[nowNode].size(); i++) {
            int nextDist = (isTired ? graph[nowNode][i].first << 1 : graph[nowNode][i].first >> 1);
            int nextNode = graph[nowNode][i].second;

            if (distWolf[nextNode][!isTired] <= distWolf[nowNode][isTired] + nextDist) continue;
            distWolf[nextNode][!isTired] = distWolf[nowNode][isTired] + nextDist;

            q.push({distWolf[nextNode][!isTired], {!isTired, nextNode}});
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        d <<= 1;
        graph[a].push_back({d, b});
        graph[b].push_back({d, a});
    }

    for (int i = 1; i <= N; i++) {
        distFox[i] = 1e9;
        distWolf[i][0] = 1e9;
        distWolf[i][1] = 1e9;
    }

    solveFox();
    solveWolf();

    int ans = 0;
    for (int i = 2; i <= N; i++) {
        if (distFox[i] < min(distWolf[i][0], distWolf[i][1])) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}