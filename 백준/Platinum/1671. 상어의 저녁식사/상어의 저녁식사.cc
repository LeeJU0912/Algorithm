#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

vector<pair<int, pair<int, int>>> save;

vector<int> graph[51];

int matching[51];
bool visited[51];

int ans;

int comp(int a, int b) {
    if (save[a].first == save[b].first && save[a].second.first == save[b].second.first && save[a].second.second == save[b].second.second) return 2;
    else if (save[a].first >= save[b].first && save[a].second.first >= save[b].second.first && save[a].second.second >= save[b].second.second) return 1;
    else if (save[a].first <= save[b].first && save[a].second.first <= save[b].second.first && save[a].second.second <= save[b].second.second) return 0;
    else return -1;
}

bool dfs(int A) {
    if (visited[A]) return false;
    visited[A] = true;

    for (int B : graph[A]) {
        if (matching[B] == -1 || dfs(matching[B])) {
            matching[B] = A;
            return true;
        }
    }
    return false;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        save.push_back({a, {b, c}});
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int val = comp(i, j);
            if (val > 0) graph[i].push_back(j);
            else if (val == 0) graph[j].push_back(i);
        }
    }

    memset(matching, -1, sizeof(matching));
    for (int i = 0; i < N; i++) {
        memset(visited, false, sizeof(visited));
        if (dfs(i)) ans++;
        memset(visited, false, sizeof(visited));
        if (dfs(i)) ans++;
    }

    cout << N - ans;

    return 0;
}