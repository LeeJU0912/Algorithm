#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int r, c, k;
int board[100][100];

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

void solve() {
    int max_row = 0;
    int max_column = 0;

    for (int i = 0; i < 100; i++) {
        int row_counter = 0;
        int column_counter = 0;
        for (int j = 0; j < 100; j++) {
            if (board[i][j] != 0) column_counter++;
            if (board[j][i] != 0) row_counter++;
        }
        max_row = max(max_row, row_counter);
        max_column = max(max_column, column_counter);
    }

    if (max_row >= max_column) {
        for (int i = 0; i < 100; i++) {
            map<int, int> mp;
            for (int j = 0; j < 100; j++) {
                if (board[i][j] == 0) continue;
                mp[board[i][j]]++;
            }
            vector<pair<int, int>> temp;
            for (auto x : mp) {
                temp.push_back(x);
            }
            sort(temp.begin(), temp.end(), comp);

            for (int j = 0; j < 100; j += 2) {
                if (j / 2 >= temp.size()) {
                    board[i][j] = 0;
                    board[i][j + 1] = 0;
                }
                else {
                    board[i][j] = temp[j / 2].first;
                    board[i][j + 1] = temp[j / 2].second;
                }
            }
        }
    }
    else {
        for (int i = 0; i < 100; i++) {
            map<int, int> mp;
            for (int j = 0; j < 100; j++) {
                if (board[j][i] == 0) continue;
                mp[board[j][i]]++;
            }
            vector<pair<int, int>> temp;
            for (auto x : mp) {
                temp.push_back(x);
            }
            sort(temp.begin(), temp.end(), comp);

            for (int j = 0; j < 100; j += 2) {
                if (j / 2 >= temp.size()) {
                    board[j][i] = 0;
                    board[j + 1][i] = 0;
                }
                else {
                    board[j][i] = temp[j / 2].first;
                    board[j + 1][i] = temp[j / 2].second;
                }
            }
        }
    }
}

int main() {
    FastIO

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i <= 100; i++) {
        if (board[r - 1][c - 1] == k) {
            cout << i;
            return 0;
        }
        solve();
    }

    cout << -1;

    return 0;
}