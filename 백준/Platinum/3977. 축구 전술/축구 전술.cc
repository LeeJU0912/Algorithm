#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<vector<int>> graph;

vector<vector<int>> SCC;

bool indegree[100000];
int group[100000];

stack<int> stk;

int parent[100000];
bool visited[100000];
int scc_counter = 1;

int dfs(int now) {
    parent[now] = scc_counter++;
    stk.push(now);

    int p = parent[now];

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];

        if (parent[next] == -1) p = min(p, dfs(next));
        else if (!visited[next]) p = min(p, parent[next]);
    }

    if (p == parent[now]) {
        vector<int> scc;

        while(true) {
            int temp = stk.top();
            stk.pop();

            scc.push_back(temp);
            visited[temp] = true;

            group[temp] = SCC.size();

            if (temp == now) break;
        }
        SCC.push_back(scc);
    }

    return p;
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        cin >> N >> M;

        SCC.clear();
        graph = vector<vector<int>>(N);
        memset(parent, -1, sizeof(parent));
        memset(visited, false, sizeof(visited));
        memset(indegree, false, sizeof(indegree));

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
        }

        for (int i = 0; i < N; i++) {
            if (parent[i] == -1) dfs(i);
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int next = graph[i][j];

                if (group[i] != group[next]) {
                    indegree[group[next]] = true;
                }
            }
        }

        vector<vector<int>> ans;

        for (int i = 0; i < SCC.size(); i++) {
            if (!indegree[i]) ans.push_back(SCC[i]);
        }

        if (ans.size() != 1) {
            cout << "Confused" << '\n';
        }
        else {
            sort(ans[0].begin(), ans[0].end());
            for (int i = 0; i < ans[0].size(); i++) {
                cout << ans[0][i] << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}