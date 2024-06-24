#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> graph[52];

int capacity[52][52];
int flow[52][52];

int ans;

int convert(char a) {
    if (a >= 'a' && a <= 'z') {
        return a - 'a';
    }
    else {
        return a - 'A' + 26;
    }
}

void solve(int source, int sink) {

    while(true) {
        int prev[52];
        memset(prev, -1, sizeof(prev));

        queue<int> q;
        q.push(source);

        while(!q.empty() && prev[sink] == -1) {
            int now = q.front();
            q.pop();

            for (int i = 0; i < graph[now].size(); i++) {
                int next = graph[now][i];

                if (capacity[now][next] - flow[now][next] <= 0) continue;
                if (prev[next] != -1) continue;

                q.push(next);
                prev[next] = now;
                if (next == sink) break;
            }
        }

        if (prev[sink] == -1) break;

        int mini = INT_MAX;
        for (int i = sink; i != source; i = prev[i]) {
            mini = min(mini, capacity[prev[i]][i] - flow[prev[i]][i]);
        }
        for (int i = sink; i != source; i = prev[i]) {
            flow[prev[i]][i] += mini;
            flow[i][prev[i]] -= mini;
        }

        ans += mini;
    }
}

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b;
        int c;
        cin >> a >> b >> c;

        int convA = convert(a);
        int convB = convert(b);

        capacity[convA][convB] = capacity[convB][convA] += c;

        graph[convA].push_back(convB);
        graph[convB].push_back(convA);
    }

    solve(26, 51);

    cout << ans;

    return 0;
}