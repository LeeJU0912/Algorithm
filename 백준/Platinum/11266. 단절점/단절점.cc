#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<vector<int>> graph;
vector<bool> is_cut_vertex;

vector<int> visited_order;
int order, cut_cnt;

int FindCutVertex(int now_idx, bool is_root) {
    visited_order[now_idx] = ++order; // DFS로 파고 들어가면서 순서 기록
    int min_order = visited_order[now_idx]; // 현재의 위치를 방문 순서의 기준으로 잡는다.
    int children = 0;

    for (int i = 0; i < graph[now_idx].size(); i++) { // DFS 코드
        int next_idx = graph[now_idx][i]; // 다음 방문 노드
        if (visited_order[next_idx] == -1) { // 방문하지 않은 노드라면,
            children++; // 그 노드와 연결 된 자식 노드 갯수 추가.
            // 다음 노드의 가능한 방문 순서가 가장 작은 root 노드를 찾는다.
            int subtree_min_order = FindCutVertex(next_idx, false);

            //다음 노드의 root 노드가 현재 노드보다 방문 순서 같거나(바로 자식노드거나) 이후라면(더 자식 노드와 연결될 경우)
            if (!is_root && subtree_min_order >= visited_order[now_idx] && !is_cut_vertex[now_idx]) {
                is_cut_vertex[now_idx] = true; // 그 지점은 자를 수 있다.
                cut_cnt++;
            }

            min_order = min(min_order, subtree_min_order);
        }
        else { // 이미 방문한 노드라면
            // 반드시 먼저 방문했던 노드이기에 부분 그래프 안에서의 min_order 파악 가능.
            min_order = min(min_order, visited_order[next_idx]);
        }
    }

    // root 노드 처리
    if (is_root && !is_cut_vertex[now_idx]) {
        // 자식 노드가 2개 이상일 경우에만 root 노드가 절단점이 될 수 있다. 그래프 2개 이상 만들어야 하기 때문.
        is_cut_vertex[now_idx] = (children >= 2);
        if (is_cut_vertex[now_idx]) cut_cnt++;
    }

    return min_order;
}

int main() {
    FastIO

    int V, E;
    cin >> V >> E;

    graph = vector<vector<int>>(V + 1);
    visited_order = vector<int>(V + 1, -1); // 방문 순서 -1로 초기화
    is_cut_vertex = vector<bool>(V + 1, false);

    for (int i = 0; i < E; i++) { // 그래프 생성
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) { // 모든 정점이 이어져 있지 않을 수 있으니 모든 정점 탐색
        if (visited_order[i] == -1){ // 한 번도 방문하지 않은 점이라면 탐색 시도
            FindCutVertex(i, true);
        }
    }

    cout << cut_cnt << '\n';

    for (int i = 1; i <= V; i++) {
        if (is_cut_vertex[i]) {
            cout << i << ' ';
        }
    }

    return 0;
}