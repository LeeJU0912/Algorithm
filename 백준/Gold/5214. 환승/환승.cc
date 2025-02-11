#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K, M;
vector<int> tubeToStation[100001];
vector<int> stationToTube[100001];
bool visited[100001];
int ans = INT_MAX;

void bfs() {
    queue<pair<int, int>> q;
    visited[1] = true;

    for (int i = 0; i < stationToTube[1].size(); i++) {
        int tube = stationToTube[1][i];

        for (int j = 0; j < tubeToStation[tube].size(); j++) {
            int otherStation = tubeToStation[tube][j];
            if (visited[otherStation]) continue;
            visited[otherStation] = true;
            q.push({0, otherStation});
        }
    }

    while(!q.empty()) {
        int nowCnt = q.front().first;
        int nowNode = q.front().second;
        q.pop();

        if (nowNode == N) {
            ans = min(ans, nowCnt + 2);
            continue;
        }

        for (int i = 0; i < stationToTube[nowNode].size(); i++) {
            int tube = stationToTube[nowNode][i];

            for (int j = 0; j < tubeToStation[tube].size(); j++) {
                int otherStation = tubeToStation[tube][j];
                if (visited[otherStation]) continue;
                visited[otherStation] = true;
                q.push({nowCnt + 1, otherStation});
            }
        }
    }
}

int main() {
    FastIO

    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            tubeToStation[i].push_back(x);
            stationToTube[x].push_back(i);
        }
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    bfs();

    cout << (ans == INT_MAX ? -1 : ans);

    return 0;
}