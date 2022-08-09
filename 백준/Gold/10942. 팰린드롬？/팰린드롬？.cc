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

int N, M;
int board[2001];
int check[2001][2001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> board[i];
    }

    for (int i = 1; i <= N; i++) {
        check[i][i] = 1;
        if (i != 1 && board[i - 1] == board[i]) {
            check[i - 1][i] = 1;
        }
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; i + j <= N; j++) {
            if (board[j] == board[i + j] && check[j + 1][i + j - 1] == 1) {
                check[j][i + j] = 1;
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int S, E;
        cin >> S >> E;

        cout << check[S][E] << '\n';
    }

    return 0;
}