#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, X;

vector<int> graph[100001];
vector<int> graph_reverse[100001];

bool visited[100001];

int findParentSize() {
    queue<int> q;
    q.push(X);

    int ret = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph_reverse[now].size(); i++) {
            int next = graph_reverse[now][i];
            if (visited[next]) continue;
            visited[next] = true;

            ret++;
            q.push(next);
        }
    }

    return ret;
}

int findChildSize() {
    queue<int> q;
    q.push(X);

    int ret = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (visited[next]) continue;
            visited[next] = true;

            ret++;
            q.push(next);
        }
    }

    return ret;
}

int main() {
    FastIO

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        graph[A].push_back(B);
        graph_reverse[B].push_back(A);
    }

    int sizeUp = findParentSize();
    int sizeDown = findChildSize();
    int left = N - sizeUp - sizeDown - 1;

    cout << sizeUp + 1 << ' ' << sizeUp + left + 1;

    return 0;
}