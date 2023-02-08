#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<vector<int>> graph;
stack<int> stk;
vector<int> visited_order;
vector<bool> scc_chk;
vector<vector<int>> scc_saved;

int order;

int SCC(int now) {
    order++; // 다음 노드를 방문할 때마다 방문 순서가 1씩 증가한다.
    // 현재 노드에서의 최소 방문 순서 = 지금 노드 위치에서의 순서
    int min_order = visited_order[now] = order;
    stk.push(now);

    // DFS 탐색 시도
    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i]; // 다음 노드의 index

        // 만약 인접한 노드를 한 번도 방문하지 않았다면,
        if (visited_order[next] == -1) {
            // 이후의 최소 방문 순서와 지금의 최소 방문 순서를 비교하여 갱신한다.
            min_order = min(min_order, SCC(next));
        }
        // 인접한 노드를 방문하였고, scc 구성을 한 번도 하지 않았다면,
        else if (!scc_chk[next]) {
            // 방문한 인접 노드의 방문 순서와 최소 방문 순서를 비교하여 갱신한다.
            min_order = min(min_order, visited_order[next]);
        }
    }

    /* 만약 최소 방문 순서를 갱신했음에도 현재와 동일하다면,
     * 한바퀴 돌아서 다시 지금 노드에 방문을 했거나,
     * 다른 곳에 가지 못하기 때문에 지금 노드 순서 = 최소 순서 초기값으로부터 갱신되지 않는다.
     * 1. 아무 노드로도 이동이 불가능한 외톨이 노드거나
     * 2. 사이클이 형성되는(다시 원래 자리로 돌아갈 수 있는) 그래프이다.
     */
    if (min_order == visited_order[now]) {
        int temp;
        vector<int> new_scc; // 새로운 scc를 형성한다.
        while(true) {
            temp = stk.top();
            stk.pop();
            scc_chk[temp] = true; // scc에 구성된 노드를 제외하기 위한 체크 수단.
            new_scc.push_back(temp);
            if (temp == now) break;
            // 스택에서 now 값이 나올 때까지 빼낸다. scc를 구성하는 노드 중 가장 먼저 들어간 노드가 now 노드이기 때문이다.
        }
        scc_saved.push_back(new_scc);
    }

    return min_order;
}

int main() {
    FastIO

    int V, E;
    cin >> V >> E;

    graph = vector<vector<int>>(V + 1);
    scc_chk = vector<bool>(V + 1, false);
    visited_order = vector<int>(V + 1, -1); // 방문 순서 -1로 초기화

    for (int i = 0; i < E; i++) { // 단방향 그래프 생성
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    for (int i = 1; i <= V; i++) { // 모든 정점이 이어져 있지 않을 수 있으니 모든 정점 탐색
        if (visited_order[i] == -1){ // 한 번도 방문하지 않은 점이라면 탐색 시도
            SCC(i);
        }
    }

    cout << scc_saved.size() << '\n';

    for (int i = 0; i < scc_saved.size(); i++) {
        sort(scc_saved[i].begin(), scc_saved[i].end());
    }

    sort(scc_saved.begin(), scc_saved.end());

    for (int i = 0; i < scc_saved.size(); i++) {
        for (auto j : scc_saved[i]) {
            cout << j << ' ';
        }
        cout << -1 << '\n';
    }

    return 0;
}