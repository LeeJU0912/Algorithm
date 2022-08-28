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

int N;
char palete[3072][6144];

void star(int x, int y, int n) {
    if (n == 3) {
        palete[x][y] = '*';
        palete[x + 1][y - 1] = '*';
        palete[x + 1][y + 1] = '*';
        palete[x + 2][y - 2] = '*';
        palete[x + 2][y - 1] = '*';
        palete[x + 2][y] = '*';
        palete[x + 2][y + 1] = '*';
        palete[x + 2][y + 2] = '*';
    }
    else {
        star(x, y, n / 2);
        star(x + n / 2, y - n / 2, n / 2);
        star(x + n / 2, y + n / 2, n / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    memset(palete, ' ', sizeof(palete));

    star(0, N - 1, N); // 시작점, 진행상황

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N * 2 - 1; j++) {
            cout << palete[i][j];
        }
        cout << '\n';
    }

    return 0;
}