#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

vector<int> ordering;
vector<int> save[401];
int board[401][401];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

pair<int, int> get_friend(int x, int y, int idx) {
    int now_friend = 0;
    int now_blank = 0;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
        if (board[next_x][next_y] == 0) now_blank++;
        else {
            for (int j = 0; j < 4; j++) {
                if (save[idx][j] == board[next_x][next_y]) now_friend++;
            }
        }
    }

    return {now_friend, now_blank};
}

void fill_student(int idx) {
    int max_friend = -1;
    int max_blank = -1;
    int now_x = 0;
    int now_y = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) continue;
            pair<int, int> count = get_friend(i, j, idx);
            if (count.first > max_friend) {
                max_friend = count.first;
                max_blank = count.second;
                now_x = i;
                now_y = j;
            }
            else if (count.first == max_friend) {
                if (count.second > max_blank) {
                    max_blank = count.second;
                    now_x = i;
                    now_y = j;
                }
            }
        }
    }

    board[now_x][now_y] = idx;
}

void get_satisfaction() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int counter = 0;
            for (int k = 0; k < 4; k++) {
                int next_x = i + dx[k];
                int next_y = j + dy[k];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;

                for (int l = 0; l < 4; l++) {
                    if (save[board[i][j]][l] == board[next_x][next_y]) counter++;
                }
            }

            if (counter == 1) {
                ans++;
            }
            else if (counter == 2) {
                ans += 10;
            }
            else if (counter == 3) {
                ans += 100;
            }
            else if (counter == 4) {
                ans += 1000;
            }
        }
    }
}

void solve() {
    for (int i = 0; i < N * N; i++) {
        fill_student(ordering[i]);
    }

    get_satisfaction();
}

int main() {
    FastIO

    cin >> N;
    for (int j = 1; j <= N * N; j++) {
        int now, a, b, c, d;
        cin >> now >> a >> b >> c >> d;
        save[now].push_back(a);
        save[now].push_back(b);
        save[now].push_back(c);
        save[now].push_back(d);
        ordering.push_back(now);
    }

    solve();
    
    cout << ans;

    return 0;
}