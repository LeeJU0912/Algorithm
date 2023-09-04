#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int m;

vector<int> graph[501];
bool chk[501];

int main() {
    FastIO

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;

    for (int j = 0; j < graph[1].size(); j++) {
        q.push(graph[1][j]);
    }

    for (int i = 0; i < 2; i++) {
        int size = q.size();

        for (int j = 0; j < size; j++) {
            int now = q.front();
            q.pop();
            chk[now] = true;


            for (int k = 0; k < graph[now].size(); k++) {
                q.push(graph[now][k]);
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (chk[i]) ans++;
    }

    cout << ans;

    return 0;
}