#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
int cost[11];
vector<int> save[11];
bool red[11];

int cost_all;

int ans = INT_MAX;

int chk_connection_red(int start) {
    int hap = 0;

    vector<bool> visited(N + 1, false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        hap += cost[now];

        for (int i = 0; i < save[now].size(); i++) {
            int next = save[now][i];

            if (!red[next]) continue;
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    return hap;
}

int chk_connection_blue(int start) {
    int hap = 0;

    vector<bool> visited(N + 1, false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        hap += cost[now];

        for (int i = 0; i < save[now].size(); i++) {
            int next = save[now][i];

            if (red[next]) continue;
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }

    return hap;
}

void make_red(int start) {
    int red_start = 0;
    int blue_start = 0;

    for (int i = 1; i <= N; i++) {
        if (red[i]) red_start = i;
        else blue_start = i;
    }

    if (red_start && blue_start) {
        int r = chk_connection_red(red_start);
        int b = chk_connection_blue(blue_start);
        if (r + b == cost_all) ans = min(ans, abs(r - b));
    }

    for (int i = start + 1; i <= N; i++) {
        if (red[i]) continue;
        red[i] = true;
        make_red(i);
        red[i] = false;
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        cost_all += cost[i];
    }

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;

        for (int j = 0; j < temp; j++) {
            int temp2;
            cin >> temp2;
            save[i].push_back(temp2);
        }
    }

    for (int i = 1; i <= N; i++) {
        red[i] = true;
        make_red(i);
        red[i] = false;
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }

    return 0;
}