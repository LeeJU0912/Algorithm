#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<int> graph[51];
int erase_node;
int ans;

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if (graph[now].empty()) ans++;

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (next == erase_node) {
                if (graph[now].size() == 1) ans++;
                continue;
            }
            q.push(next);
        }
    }
}

int main() {
    FastIO

    int N;
    cin >> N;

    int root_node;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp == -1) {
            root_node = i;
            continue;
        }
        graph[temp].push_back(i);
    }

    cin >> erase_node;
    if (erase_node == root_node) {
        cout << 0;
        return 0;
    }

    bfs(root_node);

    cout << ans;

    return 0;
}