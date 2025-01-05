#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
set<int> graph[100001];
vector<int> save;

bool visited[100001];

bool solve() {
    int idx = 0;
    if (save[idx] != 1) return false;
    idx++;

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        while(true) {
            int nextTODO = save[idx];

            if (graph[now].find(nextTODO) != graph[now].end()) {
                q.push(nextTODO);
                idx++;
            }
            else break;
        }
    }

    if (idx != N) return false;
    else return true;
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        save.push_back(x);
    }

    cout << solve();

    return 0;
}