#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int board[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int ans;

void first_search() {
    for (int i = 0; i < N; i++) {
        int counter = 1;
        for (int j = 1; j < N; j++) {
            if (board[i][j] == board[i][j - 1]) counter++;
            else {
                ans = max(ans, counter);
                counter = 1;
            }
            ans = max(ans, counter);
        }
    }
    for (int i = 0; i < N; i++) {
        int counter = 1;
        for (int j = 1; j < N; j++) {
            if (board[j][i] == board[j - 1][i]) counter++;
            else {
                ans = max(ans, counter);
                counter = 1;
            }
            ans = max(ans, counter);
        }
    }
}

void swap(int a, int b, int c, int d) {
    int temp = board[a][b];
    board[a][b] = board[c][d];
    board[c][d] = temp;
}

void search(int a, int b) {
    int counter1 = 1;
    int counter2 = 1;
    for (int i = 1; i < N; i++) {
        if (board[a][i] == board[a][i - 1]) counter1++;
        else {
            ans = max(ans, counter1);
            counter1 = 1;
        }
        if (board[i][b] == board[i - 1][b]) counter2++;
        else {
            ans = max(ans, counter2);
            counter2 = 1;
        }
        ans = max(ans, counter1);
        ans = max(ans, counter2);
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            if (s[j] == 'C') {
                board[i][j] = 1;
            }
            else if (s[j] == 'P') {
                board[i][j] = 2;
            }
            else if (s[j] == 'Z') {
                board[i][j] = 3;
            }
            else {
                board[i][j] = 4;
            }
        }
    }

    first_search();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 4; k++) {
                int next_x = i + dx[k];
                int next_y = j + dy[k];

                if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;

                swap(i, j, next_x, next_y);
                search(next_x, next_y);
                swap(next_x, next_y, i, j);
            }
        }
    }

    cout << ans;

    return 0;
}