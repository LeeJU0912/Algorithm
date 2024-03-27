#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M, K;
int board[11][11];
int A[11][11];
vector<int> trees[11][11];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sort(trees[i][j].begin(), trees[i][j].end());

            int hap = 0;
            for (int k = 0; k < trees[i][j].size(); k++) {
                int age = trees[i][j][k];

                if (board[i][j] < age) {
                    while(trees[i][j].size() != k) {
                        hap += trees[i][j].back() / 2;
                        trees[i][j].pop_back();
                    }
                    break;
                }

                board[i][j] -= age;
                trees[i][j][k]++;
            }
            board[i][j] += hap;
        }
    }
}

void fall() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < trees[i][j].size(); k++) {
                int age = trees[i][j][k];
                if (age % 5 == 0) {
                    for (int l = 0; l < 8; l++) {
                        int next_x = i + dx[l];
                        int next_y = j + dy[l];

                        if (next_x > N || next_x <= 0 || next_y > N || next_y <= 0) continue;
                        trees[next_x][next_y].push_back(1);
                    }
                }
            }
        }
    }
}

void winter() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            board[i][j] += A[i][j];
        }
    }
}

int main() {
    FastIO

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            board[i][j] = 5;
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        trees[x][y].push_back(z);
    }

    for (int i = 0; i < K; i++) {
        spring();
        fall();
        winter();
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += trees[i][j].size();
        }
    }

    cout << ans;

    return 0;
}