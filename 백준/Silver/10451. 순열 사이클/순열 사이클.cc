#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        int ans = 0;
        int N;
        cin >> N;
        vector<int> save(N + 1);
        vector<bool> visited(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> save[i];
        }
        for (int i = 1; i <= N; i++) {
            if (visited[i]) continue;
            int now = save[i];
            ans++;
            while(!visited[now]) {
                visited[now] = true;
                now = save[now];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}