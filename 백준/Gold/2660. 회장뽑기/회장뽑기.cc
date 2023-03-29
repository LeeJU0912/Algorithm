#include <bits/stdc++.h>
using namespace std;

int N;

vector<int> graph[51];

bool visited[51];
int counter;
int ans;

vector<int> answer[51];

void bfs(int idx) {
    queue<int> q;
    q.push(idx);
    visited[idx] = true;

    while(true) {
        int queue_now = q.size();
        counter += queue_now;

        if (counter == N) break;

        for (int x = 0; x < queue_now; x++) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < graph[now].size(); i++) {
                int next = graph[now][i];

                if (visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
        ans++;
    }
    answer[ans - 1].push_back(idx);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    int a, b;

    while(true) {
        cin >> a >> b;

        if (a == -1 && b == -1) break;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));
        counter = 0;
        ans = 0;

        bfs(i);
    }

    for (int i = 0; i < 51; i++) {
        if (!answer[i].empty()) {
            cout << i + 1 << ' ' << answer[i].size() << '\n';

            sort(answer[i].begin(), answer[i].end());
            for (auto j : answer[i]) {
                cout << j << ' ';
            }

            break;
        }
    }


    return 0;
}