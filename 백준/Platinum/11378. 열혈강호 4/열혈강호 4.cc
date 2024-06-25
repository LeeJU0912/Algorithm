#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

struct EDGE {
    int to, capacity, flow;

    EDGE* reverse;

    int left() const {
        return capacity - flow;
    }

    void update(int x) {
        flow += x;
        reverse->flow -= x;
    }
};

int N, M, K;
vector<EDGE*> graph[2003];

int ans;

void makeEdge(int a, int b, int capacity) {
    EDGE* ab = new EDGE();
    EDGE* ba = new EDGE();

    ab->to = b;
    ab->flow = 0;
    ab->capacity = capacity;
    ab->reverse = ba;

    ba->to = a;
    ba->flow = 0;
    ba->capacity = 0;
    ba->reverse = ab;

    graph[a].push_back(ab);
    graph[b].push_back(ba);
}

void solve(int source, int sink) {

    while(true) {
        EDGE* road[2003];
        int parent[2003];
        memset(parent, -1, sizeof(parent));

        queue<int> q;
        q.push(source);

        while(!q.empty() && parent[sink] == -1) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < graph[now].size(); i++) {
                auto next = graph[now][i];

                if (next->left() <= 0) continue;
                if (parent[next->to] != -1) continue;

                q.push(next->to);
                parent[next->to] = now;
                road[next->to] = next;

                if (next->to == sink) break;
            }
        }

        if (parent[sink] == -1) return;

        int mini = INT_MAX;
        for (int i = sink; i != source; i = parent[i]) {
            mini = min(mini, road[i]->left());
        }
        for (int i = sink; i != source; i = parent[i]) {
            road[i]->update(mini);
        }

        ans += mini;
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;

    makeEdge(0, 2002, K);

    for (int i = 1; i <= N; i++) {
        makeEdge(0, i, 1);
        makeEdge(2002, i, K);
    }
    for (int i = 1; i <= M; i++) {
        makeEdge(i + 1000, 2001, 1);
    }

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        for (int j = 0; j < temp; j++) {
            int work;
            cin >> work;
            makeEdge(i, work + 1000, 1);
        }
    }

    solve(0, 2001);

    cout << ans;

    return 0;
}