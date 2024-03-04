#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool visited[1501][1501];

int main() {
    FastIO

    vector<int> save(3);

    int hap = 0;
    for (int i = 0; i < 3; i++) {
        cin >> save[i];
        hap += save[i];
    }

    if (hap % 3) {
        cout << 0;
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({save[0], save[1]});
    visited[save[0]][save[1]] = true;

    while(!q.empty()) {
        auto now = q.front();
        q.pop();

        int now2[3] = {now.first, now.second, hap - now.first - now.second};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (now2[i] < now2[j]) {
                    int next1 = now2[i] * 2;
                    int next2 = now2[j] - now2[i];
                    if (visited[next1][next2]) continue;
                    visited[next1][next2] = true;

                    q.push({next1, next2});
                }
            }
        }
    }

    cout << visited[hap / 3][hap / 3];

    return 0;
}