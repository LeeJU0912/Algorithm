#include <bits/stdc++.h>
using namespace std;

bool adj[501][501]; // 인접하고 있는지 표시하는 행렬
int degree[501]; // 각 정점 별 차수

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int TC;
    cin >> TC;

    while(TC--) {
        memset(adj, false, sizeof(adj));
        memset(degree, 0, sizeof(degree));

        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        // 모든 두 정점 사이에 대한 인접행렬 생성
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                adj[v[i]][v[j]] = true;
                degree[v[j]]++; // 목적지로 갈 수 있는 정점들의 개수 기록
            }
        }


        int m;
        cin >> m;

        
        // 위상정렬 그래프 만들기
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if (adj[a][b]) { // 둘 사이의 연결이 이미 존재하다면
                adj[a][b] = false;
                degree[b]--;
                adj[b][a] = true; // 서로 위치를 바꾼다.
                degree[a]++;
            }
            else { // 둘 사이의 연결이 아얘 없다면 반대의 경우에는 무조건 존재한다. 따라서 반대로 시도한다.
                degree[a]--;
                adj[b][a] = false;
                adj[a][b] = true;
                degree[b]++;
            }
        }


        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (!degree[i]) { // i번 정점으로 가는 정점이 아얘 없을 경우, 이 지점에서 탐색을 시작한다.
                q.push(i);
            }
        }

        vector<int> ans;

        bool error = false;

        while(!q.empty()) {
            if (q.size() >= 2) { // 정답이 애매모호하기 때문에 하나의 답을 도출할 수 없으므로 에러.
                error = true;
                break;
            }

            int now = q.front();
            q.pop();
            ans.push_back(now);

            for (int i = 1; i <= n; i++) {
                if (adj[now][i]) { // 다음 연결된 정점으로 이동한다.
                    int next = i;

                    if (--degree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }

        if (error) {
            cout << "?\n";
            continue;
        }

        if (ans.size() != n) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        else {
            for (auto x : ans) {
                cout << x << ' ';
            }
            cout << '\n';
        }

    }

    return 0;
}