#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool sosu[10000];
bool visited[10000];

string a, b;

int ans;

void solve() {
    queue<pair<int, string>> q;

    q.push({0, a});

    while(!q.empty()) {
        int count = q.front().first;
        string now = q.front().second;
        q.pop();

        if (now == b) {
            ans = min(ans, count);
            break;
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0) continue;
                if (now[i] == j) continue;
                string next = now;
                next[i] = j + '0';
                int next_int = stoi(next);
                if (visited[next_int]) continue;
                if (sosu[next_int]) continue;
                visited[next_int] = true;

                q.push({count + 1, next});
            }
        }
    }
}

int main() {
    FastIO

    for (int i = 2; i < 10000; i++) {
        if (sosu[i]) continue;
        for (int j = 2; i * j < 10000; j++) {
            sosu[i * j] = true;
        }
    }

    int T;
    cin >> T;

    while(T--) {
        ans = INT_MAX;
        memset(visited, false, sizeof(visited));

        cin >> a >> b;

        solve();

        if (ans == INT_MAX) {
            cout << -1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    return 0;
}