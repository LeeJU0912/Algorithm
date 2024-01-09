#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<int> graph;
int matching[51];
bool visited[51];

bool not_sosu[2001];

int pick;
int counter;

vector<int> ans;

bool dfs(int A) {
    if (visited[A]) return false;
    visited[A] = true;

    for (int i = 1; i < N; i++) {
        if (A == i || i == pick) continue;
        if (not_sosu[graph[A] + graph[i]]) continue;

        if (matching[i] == -1) {
            counter++;
            matching[i] = A;
            return true;
        }
    }

    for (int i = 1; i < N; i++) {
        if (A == i || i == pick) continue;
        if (not_sosu[graph[A] + graph[i]]) continue;

        if (dfs(matching[i])) {
            matching[i] = A;
            return true;
        }
    }

    return false;
}

int main() {
    FastIO

    for (int i = 2; i <= sqrt(2000); i++) {
        if (not_sosu[i]) continue;
        for (int j = 2; i * j <= 2000; j++) {
            not_sosu[i * j] = true;
        }
    }

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        graph.push_back(temp);
    }

    for (int i = 1; i < N; i++) {
        if (not_sosu[graph[0] + graph[i]]) continue;
        memset(matching, -1, sizeof(matching));
        matching[0] = i;
        matching[i] = 0;
        pick = i;

        counter = 2;

        for (int j = 1; j < N; j++) {
            if (j == pick) continue;
            memset(visited, false, sizeof(visited));
            dfs(j);
        }

        if (counter == N) ans.push_back(graph[i]);
    }

    if (ans.empty()) {
        cout << -1;
    }
    else {
        sort(ans.begin(), ans.end());
        for (int i : ans) {
            cout << i << ' ';
        }
    }

    return 0;
}