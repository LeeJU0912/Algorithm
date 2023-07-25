#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int board[51][51];
bool visited[13];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int ans = INT_MAX;

void solve(int idx, int counter) {
    if (counter == M) {
        int temp = 0;
        for (int i = 0; i < house.size(); i++) {
            int mini = INT_MAX;

            for (int j = 0; j < chicken.size(); j++) {
                if (!visited[j]) continue;
                mini = min(mini, abs(chicken[j].first - house[i].first) + abs(chicken[j].second - house[i].second));
            }

            temp += mini;
        }

        ans = min(ans, temp);
        return;
    }
    for (int i = idx + 1; i < chicken.size(); i++) {
        visited[i] = true;
        solve(i, counter + 1);
        visited[i] = false;
    }
}

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1) {
                house.push_back({i, j});
            }
            else if (board[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < chicken.size(); i++) {
        visited[i] = true;
        solve(i, 1);
        visited[i] = false;
    }



    cout << ans;

    return 0;
}