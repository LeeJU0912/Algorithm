#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<int> graph[2001];
vector<int> rev_graph[2001];

bool visited[2001];
int SCC[2001];

int scc_counter = 1;

stack<int> stk;

void dfs(int now) {
    visited[now] = true;

    for (int next : graph[now]) {
        if (visited[next]) continue;
        dfs(next);
    }
    stk.push(now);
}

void rev_dfs(int now) {
    visited[now] = true;
    SCC[now] = scc_counter;

    for (int next : rev_graph[now]) {
        if (visited[next]) continue;
        rev_dfs(next);
    }
}

void getSCC() {
    for (int i = 1; i <= 2 * N; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    memset(visited, false, sizeof(visited));

    while(!stk.empty()) {
        int now = stk.top();
        stk.pop();

        if (!visited[now]) {
            rev_dfs(now);
            scc_counter++;
        }
    }
}

int main() {
    FastIO

    while(cin >> N >> M) {
        bool err = false;
        scc_counter = 1;
        for (int i = 1; i <= N * 2; i++) {
            graph[i].clear();
            rev_graph[i].clear();
            SCC[i] = 0;
            visited[i] = false;
        }

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            int true_a, rev_a, true_b, rev_b;

            if (a < 0) {
                true_a = -a + N;
                rev_a = -a;
            }
            else {
                true_a = a;
                rev_a = a + N;
            }
            if (b < 0) {
                true_b = -b + N;
                rev_b = -b;
            }
            else {
                true_b = b;
                rev_b = b + N;
            }

            graph[rev_a].push_back(true_b);
            graph[rev_b].push_back(true_a);
            rev_graph[true_a].push_back(rev_b);
            rev_graph[true_b].push_back(rev_a);
        }

        getSCC();

        for (int i = 1; i <= N; i++) {
            if (SCC[i] == SCC[i + N]) {
                err = true;
                break;
            }
        }

        if (err) {
            cout << 0 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }

    return 0;
}