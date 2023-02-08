#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<vector<int>> graph;
vector<int> visited_order;

vector<pair<int, int>> bridge;

int order, cut_cnt;

int FindCutVertex(int now_idx, int parent_idx) {
    visited_order[now_idx] = ++order; // DFS로 파고 들어가면서 순서 기록
    int min_order = visited_order[now_idx]; // 현재의 위치를 방문 순서의 기준으로 잡는다.
    int a, b;

    for (int i = 0; i < graph[now_idx].size(); i++) { // DFS 코드
        int next_idx = graph[now_idx][i]; // 다음 방문 노드
        if (visited_order[next_idx] == -1) { // 방문하지 않은 노드라면,
            // 다음 노드의 가능한 방문 순서가 가장 작은 root 노드를 찾는다.
            int subtree_min_order = FindCutVertex(next_idx, now_idx);

            //다음 노드의 root 노드가 현재 노드보다 방문 순서 같거나(바로 자식노드거나) 이후라면(더 자식 노드와 연결될 경우)
            if (subtree_min_order > visited_order[now_idx]) {
                // 그 지점은 자를 수 있다.
                a = now_idx;
                b = next_idx;

                if (a > b) swap(a, b);

                bridge.emplace_back(a, b);
                cut_cnt++;
            }

            min_order = min(min_order, subtree_min_order);
        }
        else { // 이미 방문한 노드라면
            // 다음 방문하는 노드가 직전 방문 노드가 아닐 경우, 반드시 직전이 아닌 이전에 먼저 방문했던 노드이기에 부분 그래프 안에서의 min_order 파악 가능.
            if (next_idx != parent_idx) {
                min_order = min(min_order, visited_order[next_idx]);
            }
        }
    }

    return min_order;
}

int main() {
    FastIO

    int V, E;
    cin >> V >> E;

    graph = vector<vector<int>>(V + 1);
    visited_order = vector<int>(V + 1, -1); // 방문 순서 -1로 초기화

    for (int i = 0; i < E; i++) { // 그래프 생성
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= V; i++) { // 모든 정점이 이어져 있지 않을 수 있으니 모든 정점 탐색
        if (visited_order[i] == -1){ // 한 번도 방문하지 않은 점이라면 탐색 시도
            FindCutVertex(i, 0);
        }
    }

    cout << cut_cnt << '\n';

    sort(bridge.begin(), bridge.end());

    for (int i = 0; i < bridge.size(); i++) {
        cout << bridge[i].first << ' ' << bridge[i].second << '\n';
    }

    return 0;
}