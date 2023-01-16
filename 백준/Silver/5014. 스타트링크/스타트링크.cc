#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];
int ans;

void solve() {
    queue<pair<int, int>> q;
    q.emplace(S, 0);
    visited[S] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        if (now.first == G) {
            ans = now.second;
            return;
        }

        int next1 = now.first + U;
        if (next1 > 0 && next1 <= F) {
            if (!visited[next1]) {
                visited[next1] = true;
                q.emplace(next1, now.second + 1);
            }
        }
        int next2 = now.first - D;
        if (next2 > 0 && next2 <= F) {
            if (!visited[next2]) {
                visited[next2] = true;
                q.emplace(next2, now.second + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> F >> S >> G >> U >> D;

    if (S == G) {
        cout << 0;
        return 0;
    }
    
    solve();

    if (ans) {
        cout << ans;
    }
    else {
        cout << "use the stairs";
    }

    return 0;
}