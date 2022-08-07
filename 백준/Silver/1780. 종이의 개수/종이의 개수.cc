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

int table[2500][2500];
int ans[3];

void solve(int x, int y, int size) {
    int check;
    check = table[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (table[i][j] != table[x][y]) {
                solve(x, y, size / 3);
                solve(x + size / 3, y, size / 3);
                solve(x + size * 2 / 3, y, size / 3);
                solve(x, y + size / 3, size / 3);
                solve(x, y + size * 2 / 3, size / 3);
                solve(x + size / 3, y + size / 3, size / 3);
                solve(x + size / 3, y + size * 2 / 3, size / 3);
                solve(x + size * 2 / 3, y + size / 3, size / 3);
                solve(x + size * 2 / 3, y + size * 2 / 3, size / 3);
                return;
            }
        }
    }
    ans[table[x][y] + 1]++;
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
        }
    }

    solve(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}