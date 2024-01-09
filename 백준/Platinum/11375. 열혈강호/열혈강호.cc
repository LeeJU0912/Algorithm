#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<int> graph[1001];
int matching[1001];
bool visited[1001];

int ans;

bool dfs(int A) {
    if (visited[A]) return false;
    visited[A] = true;
    
    for (int i = 0; i < graph[A].size(); i++) {
        int B = graph[A][i];

        if (matching[B] == 0) {
            matching[B] = A;

            return true;
        }

        if (dfs(matching[B])) {
            matching[B] = A;

            return true;
        }
    }

    return false;
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int T;
        cin >> T;

        for (int j = 0; j < T; j++) {
            int work;
            cin >> work;

            graph[i].push_back(work);
        }
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, false, sizeof(visited));

        if (dfs(i)) ans++;
    }

    cout << ans;

    return 0;
}