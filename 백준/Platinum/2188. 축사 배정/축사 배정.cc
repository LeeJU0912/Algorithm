#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
vector<int> save[201];
int cage[201];
bool chk[201];

int ans;

bool dfs(int idx) {
    for (int i = 0; i < save[idx].size(); i++) {
        int now = save[idx][i];
        if (chk[now]) continue;
        chk[now] = true;
        if (cage[now] == 0 || dfs(cage[now])) {
            cage[now] = idx;
            return true;
        }
    }
    return false;
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int S;
        cin >> S;

        for (int j = 0; j < S; j++) {
            int temp;
            cin >> temp;
            save[i].push_back(temp);
        }
    }

    for (int i = 1; i <= N; i++) {
        memset(chk, false, sizeof(chk));
        if (dfs(i)) ans++;
    }

    cout << ans;

    return 0;
}