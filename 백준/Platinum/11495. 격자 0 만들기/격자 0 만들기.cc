#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, m;
int board[50][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int hap;

struct EDGE {
    int target, capacity, flow;
    EDGE* reverse;
    int residualCapacity() const {
        return capacity - flow;
    }
    void push(int val) {
        flow += val;
        reverse->flow -= val;
    }
};

vector<EDGE*> graph[2502];

void makeEdge(int a, int b, int capacity) {
    EDGE* ab = new EDGE();
    EDGE* ba = new EDGE();

    ab->target = b;
    ab->capacity = capacity;
    ab->flow = 0;
    ab->reverse = ba;

    ba->target = a;
    ba->capacity = 0;
    ba->flow = 0;
    ba->reverse = ab;

    graph[a].push_back(ab);
    graph[b].push_back(ba);
}

int networkFlow(int source, int sink) {

    int totalFlow = 0;
    while(true) {
        vector<int> prev(2502, -1);
        EDGE* path[2502];
        queue<int> q;
        prev[source] = source;
        q.push(source);

        while(!q.empty() && prev[sink] == -1) {
            int now = q.front();
            q.pop();

            for (auto next : graph[now]) {
                int nextNode = next->target;
                if (next->residualCapacity() > 0 && prev[nextNode] == -1) {
                    q.push(nextNode);
                    prev[nextNode] = now;
                    path[nextNode] = next;
                    if (nextNode == sink) break;
                }
            }
        }

        if (prev[sink] == -1) break;

        int flow = 1e9;
        for (int i = sink; i != source; i = prev[i]) {
            flow = min(flow, path[i]->residualCapacity());
        }
        for (int i = sink; i != source; i = prev[i]) {
            path[i]->push(flow);
        }

        totalFlow += flow;
    }

    return totalFlow;
}

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        hap = 0;
        for (int i = 0; i <= 2501; i++) {
            graph[i].clear();
        }

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> board[i][j];
                hap += board[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i % 2) {
                    if (j % 2) {
                        makeEdge(0, i * m + j, board[i][j]);
                    }
                    else {
                        makeEdge(i * m + j, 2501, board[i][j]);
                    }
                }
                else {
                    if (j % 2 == 0) {
                        makeEdge(0, i * m + j, board[i][j]);
                    }
                    else {
                        makeEdge(i * m + j, 2501, board[i][j]);
                    }
                }

                for (int k = 0; k < 4; k++) {
                    int nextX = i + dx[k];
                    int nextY = j + dy[k];

                    if (nextX < 0 || nextX >= n || nextY <= 0 || nextY > m) continue;

                    if (i % 2 == 0) {
                        if (j % 2 == 0) {
                            makeEdge(i * m + j, nextX * m + nextY, INT_MAX);
                        }
                    }
                    else {
                        if (j % 2) {
                            makeEdge(i * m + j, nextX * m + nextY, INT_MAX);
                        }
                    }
                }
            }
        }

        cout << hap - networkFlow(0, 2501) << '\n';
    }

    return 0;
}