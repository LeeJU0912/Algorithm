#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int cost[101];

vector<int> graph[101];

int group[101];
int group_count = 1;
bool finished[101];
vector<vector<int>> SCC;

stack<int> stk;

int ans;

int dfs(int start) {
    group[start] = group_count++;
    stk.push(start);

    int parent = group[start];

    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];

        if (group[next] == 0) parent = min(parent, dfs(next));
        else if (!finished[next]) parent = min(parent, group[next]);
    }

    if (parent == group[start]) {
        vector<int> temp;
        while(true) {
            int tmp = stk.top();
            stk.pop();

            temp.push_back(tmp);
            finished[tmp] = true;
            if (tmp == start) break;
        }
        SCC.push_back(temp);
    }

    return parent;
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') {
                graph[i].push_back(j + 1);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (group[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 0; i < SCC.size(); i++) {
        int mini = INT_MAX;
        for (int j = 0; j < SCC[i].size(); j++) {
            mini = min(mini, cost[SCC[i][j]]);
        }

        ans += mini;
    }

    cout << ans;

    return 0;
}