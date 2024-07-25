#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int garoHap[51];
int seroHap[51];

int ans[51][51];

struct EDGE {
    int target, capacity, flow;
    bool isReverse;
    EDGE* reverse;
    int residualCapacity() const {
        return capacity - flow;
    }
    void push(int val) {
        flow += val;
        reverse->flow -= val;
    }
};

vector<EDGE*> graph[2602];

void makeEdge(int a, int b, int capacity) {
    EDGE* ab = new EDGE();
    EDGE* ba = new EDGE();

    ab->target = b;
    ab->capacity = capacity;
    ab->flow = 0;
    ab->reverse = ba;
    ab->isReverse = false;

    ba->target = a;
    ba->capacity = 0;
    ba->flow = 0;
    ba->reverse = ab;
    ba->isReverse = true;

    graph[a].push_back(ab);
    graph[b].push_back(ba);
}

int networkFlow(int source, int sink) {
    int totalFlow = 0;
    while(true) {
        vector<int> prev(2602, -1);
        EDGE* path[2602];
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

    int hap = 0;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> garoHap[i];
        hap += garoHap[i];
        makeEdge(0, 2500 + i, garoHap[i]);
    }
    for (int i = 1; i <= N; i++) {
        cin >> seroHap[i];
        makeEdge(2550 + i, 2601, seroHap[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            makeEdge(2500 + i, 2550 + j, INT_MAX);
        }
    }

    int mini = 0;
    int maxi = 1e9;
    int chk;

    while(mini <= maxi) {
        int mid = (mini + maxi) / 2;

        for (int i = 1; i <= N; i++) {
            int idx = 2500 + i;
            for (int j = 0; j < graph[idx].size(); j++) {
                auto now = graph[idx][j];

                now->capacity = mid;
            }
        }

        for (int i = 0; i <= 2601; i++) {
            for (auto & j : graph[i]) {
                j->flow = 0;
            }
        }

        int flow = networkFlow(0, 2601);

        if (hap > flow) {
            mini = mid + 1;
        }
        else if (hap == flow) {
            chk = mid;
            for (int i = 1; i <= N; i++) {
                int idx = 2500 + i;
                for (int j = 0; j < graph[idx].size(); j++) {
                    if (graph[idx][j]->isReverse) continue;
                    int next = graph[idx][j]->target;
                    ans[i - 1][next - 2551] = graph[idx][j]->flow;
                }
            }
            maxi = mid - 1;
        }
        else {
            maxi = mid - 1;
        }
    }
    
    cout << chk << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}