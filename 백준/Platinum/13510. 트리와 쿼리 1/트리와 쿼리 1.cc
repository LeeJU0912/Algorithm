#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

pair<int, pair<int, int>> graph[100001]; // input 저장
vector<int> adj[100001]; // 인접 노드 모음
vector<int> child[100001]; // 자식 노드 모음

int base = 1;

int parent[100001]; // 부모 노드
int tree[400001]; // index tree
int node_tree_size[100001]; // 해당 노드가 위치한 부분 트리 크기
int node_tree_depth[100001]; // 전체 트리에서 해당 노드가 위치한 depth
int ancestor[100001]; // 최상위 조상 노드
int in[100001]; // 노드가 불린 순서

// 자식 노드 탐색 저장
void makeChildTree(int prev, int now) {
    for (auto next : adj[now]) {
        if (next == prev) continue;
        child[now].push_back(next);
        makeChildTree(now, next);
    }
}

// 노드 정보 수집
void build(int now) {
    node_tree_size[now] = 1;
    for (auto& next : child[now]) {
        node_tree_depth[next] = node_tree_depth[now] + 1;
        parent[next] = now;
        build(next);
        node_tree_size[now] += node_tree_size[next];

        // subtree가 무거운 것부터 정렬
        if (node_tree_size[next] > node_tree_size[child[now][0]]) swap(next, child[now][0]);
    }
}

int counter;
void makeSubtree(int now) {
    in[now] = ++counter;
    for (auto& next : child[now]) {
        // 무거운 노드에 대해 전부 체인으로 잇는다.
        if (next == child[now][0]) {
            ancestor[next] = ancestor[now];
        }
        // 가장 무거운 노드를 제외한 나머지 자식노드들은, 새로운 tree를 만든다.
        else {
            ancestor[next] = next;
        }
        makeSubtree(next);
    }
}

void update(int idx, int val) {
    int u = graph[idx].second.first;
    int v = graph[idx].second.second;

    // 현재 간선 크기 변경
    graph[idx].first = val;

    // u가 v의 부모가 되도록 설정
    if (parent[v] != u) swap(u, v);

    // tree에 반영, v가 자식 노드이므로 더 오른쪽에 있기 때문에 v부터 루트까지 segtree 갱신 시작.
    int next = base + in[v];
    tree[next] = graph[idx].first;

    while(next >>= 1) {
        tree[next] = max(tree[next * 2], tree[next * 2 + 1]);
    }
}

// subtree에서 최댓값 구하기
int maxQuery(int l, int r) {
    int val = 0;

    l |= base;
    r |= base;

    while(l <= r) {
        if (l & 1) val = max(val, tree[l++]);
        if (~r & 1) val = max(val, tree[r--]);
        l >>= 1;
        r >>= 1;
    }

    return val;
}

// u에서 v로 가는 길의 최대 비용 구하기
int query(int u, int v) {
    int val = 0;

    // 같은 subtree에 속할 때까지 레벨을 올린다.
    while(ancestor[u] != ancestor[v]) {
        if (node_tree_depth[ancestor[u]] > node_tree_depth[ancestor[v]]) {
            swap(u, v);
        }
        val = max(val, maxQuery(in[ancestor[v]], in[v]));
        v = parent[ancestor[v]];
    }

    // 같은 subtree라면, left < right가 되도록 맞춘다.
    if (in[u] > in[v]) swap(u, v);

    val = max(val, maxQuery(in[u] + 1, in[v]));
    return val;
}

int main() {
    FastIO

    cin >> N;
    while(base < N) base <<= 1;

    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[i] = {w, {u, v}};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    makeChildTree(0, 1);
    build(1);
    makeSubtree(1);

    for (int i = 1; i < N; i++) {
        update(i, graph[i].first);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int order, a, b;
        cin >> order >> a >> b;

        if (order == 1) {
            update(a, b);
        }
        else if (order == 2) {
            cout << query(a, b) << '\n';
        }
    }

    return 0;
}