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

int list[65][65];

void solve(int x, int y, int size) {
    int check = list[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (list[i][j] != check && size >= 2) {
                cout << "(";
                solve(x, y, size / 2);
                solve(x, y + size / 2, size / 2);
                solve(x + size / 2, y, size / 2);
                solve(x + size / 2, y + size / 2, size / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << check;

    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            list[i][j] = s[j] - '0';
        }
    }

    solve(0, 0, N);

    return 0;
}