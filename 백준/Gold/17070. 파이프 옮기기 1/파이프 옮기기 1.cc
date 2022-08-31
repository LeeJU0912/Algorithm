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
#include <cstdlib>
#include <utility>

using namespace std;

int counter;
int pipe[17][17];
int N;

void solve(int x, int y, int status) {
    if (x == N - 1 && y == N - 1) {
        counter++;
    }
    if (x > N - 1 || y > N - 1) return;

    if (status == 0) {
        if (pipe[x][y + 1] != 1) {
            solve(x, y + 1, 0);
        }

        if (!(pipe[x + 1][y] == 1 || pipe[x][y + 1] == 1 || pipe[x + 1][y + 1] == 1)) {
            solve(x + 1, y + 1, 2);
        }
    }
    else if (status == 1) {
        if (pipe[x + 1][y] != 1) {
            solve(x + 1, y, 1);
        }
        if (!(pipe[x + 1][y] == 1 || pipe[x][y + 1] == 1 || pipe[x + 1][y + 1] == 1)) {
            solve(x + 1, y + 1, 2);
        }
    }
    else if (status == 2) {
        if (pipe[x][y + 1] != 1) {
            solve(x, y + 1, 0);
        }
        if (pipe[x + 1][y] != 1) {
            solve(x + 1, y, 1);
        }
        if (!(pipe[x + 1][y] == 1 || pipe[x][y + 1] == 1 || pipe[x + 1][y + 1] == 1)) {
            solve(x + 1, y + 1, 2);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> pipe[i][j];
        }
    }

    solve(0, 1, 0);

    cout << counter;

    return 0;
}