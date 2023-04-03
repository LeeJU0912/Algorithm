#include <bits/stdc++.h>
using namespace std;

int N;

int indegree[501];
int const_time[501];
vector<int> graph[501];
int ans[501];

void topologySort() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            ans[i] = const_time[i];
            q.push(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        int now = q.front();
        q.pop();
        for (int j = 0; j < graph[now].size(); j++) {
            int next = graph[now][j];

            if (--indegree[next] == 0) {
                q.push(next);
            }

            ans[next] = max(ans[next], ans[now] + const_time[next]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;


    for (int i = 1; i <= N; i++) {
        int time;
        cin >> time;
        const_time[i] = time;

        int temp;
        while(true) {
            cin >> temp;

            if (temp == -1) {
                break;
            }
            indegree[i]++;

            graph[temp].push_back(i);
        }
    }

    topologySort();

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}