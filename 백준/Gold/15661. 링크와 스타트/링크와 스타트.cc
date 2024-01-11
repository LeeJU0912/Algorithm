#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n;
int graph[20][20];
bool visited[20];
int ans = INT_MAX;

int cal() {
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (visited[i] && visited[j]) {
                cnt1 += graph[i][j] + graph[j][i];
            }
            else if (!visited[i] && !visited[j]) {
                cnt2 += graph[i][j] + graph[j][i];
            }
        }
    }
    return abs(cnt1 - cnt2);
}

void combination(int cnt) {
    if (cnt == n) {
        //팀 비교
        ans =min(ans,cal());
        return;
    }
    visited[cnt] = true;
    combination(cnt + 1);
    visited[cnt] = false;
    combination(cnt + 1);
}

int main() {
    FastIO

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    combination(0);
    cout << ans;
    return 0;
}