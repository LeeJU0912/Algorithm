#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<int> graph[20001];
vector<int> rev_graph[20001];
bool visited[20001];
int SCC[20001];
int scc_counter = 1;

int ans[10001];

stack<int> stk;

void dfs(int now) {
    if (visited[now]) return;

    visited[now] = true;

    for (int i = 0; i < graph[now].size(); i++) {
        int next = graph[now][i];

        dfs(next);
    }

    stk.push(now);
}

void rev_dfs(int now) {
    if (visited[now]) return;

    visited[now] = true;
    SCC[now] = scc_counter;

    for (int i = 0; i < rev_graph[now].size(); i++) {
        int next = rev_graph[now][i];

        rev_dfs(next);
    }
}

int main() {
    FastIO

    while(cin >> N >> M) {
        scc_counter = 1;
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= N * 2; i++) {
            graph[i].clear();
            rev_graph[i].clear();
            visited[i] = false;
            SCC[i] = 0;
        }
        
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            int true_a, true_b, not_a, not_b;

            if (a < 0) {
                true_a = -a + N;
                not_a = -a;
            }
            else {
                true_a = a;
                not_a = a + N;
            }
            if (b < 0) {
                true_b = -b + N;
                not_b = -b;
            }
            else {
                true_b = b;
                not_b = b + N;
            }

            graph[not_a].push_back(true_b);
            graph[not_b].push_back(true_a);
            rev_graph[true_a].push_back(not_b);
            rev_graph[true_b].push_back(not_a);
        }

        for (int i = 1; i <= N * 2; i++) {
            if (visited[i]) continue;

            dfs(i);
        }

        memset(visited, false, sizeof(visited));

        while(!stk.empty()) {
            int now = stk.top();
            stk.pop();

            if (visited[now]) continue;

            rev_dfs(now);

            scc_counter++;
        }

        bool chk = false;
        for (int i = 1; i <= N; i++) {
            if (SCC[i] == SCC[i + N]) {
                chk = true;
                break;
            }
        }

        if (chk) {
            cout << "no" << '\n';
        }
        else {
            if (SCC[1] > SCC[1 + N]) {
                cout << "yes" << '\n';
            }
            else cout << "no" << '\n';
        }
    }

    return 0;
}