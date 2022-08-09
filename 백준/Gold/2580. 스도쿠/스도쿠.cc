#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>

using namespace std;

int sudoku[9][9];
int garo[10][10];
int sero[10][10];
int square[10][10];

void solve(int counter) {
    if (counter == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    int x = counter / 9; // 세로
    int y = counter % 9;

    if (sudoku[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (garo[x][i] == 0 && sero[y][i] == 0 && square[(x / 3) * 3 + (y / 3)][i] == 0) {
                garo[x][i] = 1;
                sero[y][i] = 1;
                square[(x / 3) * 3 + (y / 3)][i] = 1;
                sudoku[x][y] = i;
                solve(counter + 1);
                garo[x][i] = 0;
                sero[y][i] = 0;
                square[(x / 3) * 3 + (y / 3)][i] = 0;
                sudoku[x][y] = 0;
            }
        }
    }
    else solve(counter + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] != 0) {
                garo[i][sudoku[i][j]] = 1;
                sero[j][sudoku[i][j]] = 1;
                square[(i / 3) * 3 + (j / 3)][sudoku[i][j]] = 1;
            }
        }
    }

    solve(0);

    return 0;
}