#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<vector<int>> graph;
stack<int> stk;
vector<int> visited_order;
vector<bool> scc_chk;
vector<vector<int>> scc_saved;

vector<int> indegree;
vector<int> group;

int order;

int SCC(int now) {
    int min_order = visited_order[now] = ++order;
    stk.push(now);

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];
        if (visited_order[next] == -1) {
            min_order = min(min_order, SCC(next));
        }
        else if (!scc_chk[next]) {
            min_order = min(min_order, visited_order[next]);
        }
    }

    if (min_order == visited_order[now]) {
        vector<int> temp;
        while(true) {
            int tmp = stk.top();
            temp.push_back(tmp);
            stk.pop();
            group[tmp] = scc_saved.size() + 1; // ★같은 SCC 끼리 묶기
            scc_chk[tmp] = true;
            if (tmp == now) break;
        }
        scc_saved.push_back(temp);
    }

    return min_order;
}

int main() {
    FastIO

    int T;
    cin >> T;

    while(T--) {
        scc_saved.clear();
        order = 0;

        int V, E;
        cin >> V >> E;

        graph = vector<vector<int>>(V + 1);
        visited_order = vector<int>(V + 1, -1);
        scc_chk = vector<bool>(V + 1, false);
        indegree = vector<int>(V + 1, 0); // 진입 차수 초기화
        group = vector<int>(V + 1);

        for (int i = 0; i < E; i++) { // 단방향 그래프 생성
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }

        // SCC 구하기
        for (int i = 1; i <= V; i++) { // 모든 정점이 이어져 있지 않을 수 있으니 모든 정점 탐색
            if (visited_order[i] == -1){ // 한 번도 방문하지 않은 점이라면 탐색 시도
                SCC(i);
            }
        }
        
        // SCC 덩어리 중에 자기에게 들어오는 지점이 하나도 없는 점을 찾는다. (indegree = 0)
        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                int next = graph[i][j];
                if (group[i] != group[next]) {
                    indegree[group[next]] = true;
                }
            }
        }

        int result = 0;
        
        // SCC 덩어리 갯수만큼 반복해서 덩어리의 indegree 체크를 한다.
        for (int i = 1; i <= scc_saved.size(); i++) {
            if (!indegree[i]) result++;
        }

        cout << result << '\n';

    }


    return 0;
}