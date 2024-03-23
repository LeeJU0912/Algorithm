#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

vector<vector<int>> board;
vector<vector<int>> copied;

vector<pair<int, pair<int, int>>> save;
int order[8];

int ans = INT_MAX;

void fill_x(int idx) {
    int now_x = save[idx].second.first;
    int now_y = save[idx].second.second;
    copied[now_x][now_y] = 1;

    if (save[idx].first == 1) {
        if (order[idx] == 1) {
            for (int i = now_x - 1; i >= 0; i--) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
        }
        else if (order[idx] == 2) {
            for (int i = now_x + 1; i < N; i++) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
        }
        else if (order[idx] == 3) {
            for (int j = now_y - 1; j >= 0; j--) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
        else if (order[idx] == 4) {
            for (int j = now_y + 1; j < M; j++) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
    }
    else if (save[idx].first == 2) {
        if (order[idx] == 1) {
            for (int i = now_x - 1; i >= 0; i--) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int i = now_x + 1; i < N; i++) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
        }
        else {
            for (int j = now_y - 1; j >= 0; j--) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
            for (int j = now_y + 1; j < M; j++) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
    }
    else if (save[idx].first == 3) {
        if (order[idx] == 1) {
            for (int i = now_x - 1; i >= 0; i--) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y - 1; j >= 0; j--) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
        else if (order[idx] == 2) {
            for (int i = now_x - 1; i >= 0; i--) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y + 1; j < M; j++) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
        else if (order[idx] == 3) {
            for (int i = now_x + 1; i < N; i++) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y + 1; j < M; j++) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
        else if (order[idx] == 4) {
            for (int i = now_x + 1; i < N; i++) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y - 1; j >= 0; j--) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
    }
    else if (save[idx].first == 4) {
        if (order[idx] == 1) {
            for (int i = now_x + 1; i < N; i++) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y - 1; j >= 0; j--) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
            for (int j = now_y + 1; j < M; j++) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
        else if (order[idx] == 2) {
            for (int i = now_x - 1; i >= 0; i--) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y - 1; j >= 0; j--) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
            for (int j = now_y + 1; j < M; j++) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
        else if (order[idx] == 3) {
            for (int i = now_x - 1; i >= 0; i--) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int i = now_x + 1; i < N; i++) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y + 1; j < M; j++) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
        else if (order[idx] == 4) {
            for (int i = now_x - 1; i >= 0; i--) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int i = now_x + 1; i < N; i++) {
                if (copied[i][now_y] == 6) break;
                copied[i][now_y] = 1;
            }
            for (int j = now_y - 1; j >= 0; j--) {
                if (copied[now_x][j] == 6) break;
                copied[now_x][j] = 1;
            }
        }
    }
    else if (save[idx].first == 5) {
        for (int i = now_x - 1; i >= 0; i--) {
            if (copied[i][now_y] == 6) break;
            copied[i][now_y] = 1;
        }
        for (int i = now_x + 1; i < N; i++) {
            if (copied[i][now_y] == 6) break;
            copied[i][now_y] = 1;
        }
        for (int j = now_y - 1; j >= 0; j--) {
            if (copied[now_x][j] == 6) break;
            copied[now_x][j] = 1;
        }
        for (int j = now_y + 1; j < M; j++) {
            if (copied[now_x][j] == 6) break;
            copied[now_x][j] = 1;
        }
    }
}

int filling() {
    copied = board;

    for (int i = 0; i < save.size(); i++) {
        fill_x(i);
    }

    int temp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (copied[i][j] == 0) temp++;
        }
    }

    return temp;
}

void solve(int idx) {
    if (idx == save.size()) {
        ans = min(ans, filling());
        return;
    }

    for (int i = 1; i <= 4; i++) {
        order[idx] = i;
        solve(idx + 1);

        if (save[idx].first == 5) break;
        if (save[idx].first == 2) {
            if (i == 2) break;
        }
    }
}

int main() {
    FastIO

    cin >> N >> M;
    board = vector<vector<int>>(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            if (temp == 6) board[i][j] = 6;
            else if (temp != 0) {
                save.push_back({temp, {i, j}});
            }
        }
    }

    solve(0);

    cout << ans;

    return 0;
}