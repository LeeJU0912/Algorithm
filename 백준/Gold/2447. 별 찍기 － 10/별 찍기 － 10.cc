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
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>

using namespace std;

int N;
char board[6562][6562];

void draw(int x, int y, int n) {
    if (n == 1) {
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (i == x + 1 && j == y + 1) continue;
                board[i][j] = '*';
            }
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            draw(x + n * i, y + n * j, n / 3);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    memset(board, ' ', sizeof(board));

    draw(1, 1, N / 3);



    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}