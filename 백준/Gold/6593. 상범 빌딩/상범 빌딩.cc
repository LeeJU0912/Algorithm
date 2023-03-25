#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int L, R, C;
int building[31][31][31];
bool visited[31][31][31];

int dx[6] = {0, 0, 0, 0, -1 ,1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

tuple<int, int, int> start;

int ans;

void bfs(tuple<int, int, int> now) {
    queue<pair<tuple<int, int, int>, int>> q;
    q.push({now, 0});
    visited[get<0>(now)][get<1>(now)][get<2>(now)] = true;

    while(!q.empty()) {
        tuple<int, int, int> go = q.front().first;
        int counter = q.front().second;
        q.pop();

        if (building[get<0>(go)][get<1>(go)][get<2>(go)] == 3) {
            ans = counter;
            return;
        }

        for (int i = 0; i < 6; i++) {
            int next_x = get<0>(go) + dx[i];
            int next_y = get<1>(go) + dy[i];
            int next_z = get<2>(go) + dz[i];

            if (next_x < 0 || next_x >= L || next_y < 0 || next_y >= R || next_z < 0 || next_z >= C) continue;
            if (building[next_x][next_y][next_z] == 1) continue;
            if (visited[next_x][next_y][next_z]) continue;
            visited[next_x][next_y][next_z] = true;

            q.push({{next_x, next_y, next_z}, counter + 1});
        }
    }
}

int main() {
    FastIO

    while(true) {
        memset(visited, false, sizeof(visited));
        memset(building, 0, sizeof(building));
        ans = 0;

        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string s;
                cin >> s;
                for (int k = 0; k < C; k++) {
                    if (s[k] == '#') {
                        building[i][j][k] = 1;
                    }
                    else if (s[k] == 'S') {
                        building[i][j][k] = 2;
                        start = {i, j, k};
                    }
                    else if (s[k] == 'E') {
                        building[i][j][k] = 3;
                    }
                }
            }
        }

        bfs(start);

        if (ans) {
            cout << "Escaped in " << ans << " minute(s)." << '\n';
        }
        else {
            cout << "Trapped!" << '\n';
        }
    }
    
    return 0;
}