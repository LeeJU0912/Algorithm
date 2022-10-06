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
int board[10][10];
bool check[10][10];
int ans_black, ans_white;

vector<pair<int, int>> one;

bool is_possible(int x, int y) { // 어차피 아래 부분들은 비숍이 놓여 있지 않기 때문에 위에 두 대각선만 확인하면 된다.
    // 왼쪽 위쪽 대각선
    int go_x = x - 1;
    int go_y = y - 1;

    while(go_x >= 0 && go_y >= 0) {
        if (check[go_x][go_y]) return false;
        go_x--;
        go_y--;
    }

    
    // 오른쪽 위쪽 대각선
    go_x = x - 1;
    go_y = y + 1;

    while(go_x >= 0 && go_y < N) {
        if (check[go_x][go_y]) return false;
        go_x--;
        go_y++;
    }

    return true;
}

void dfs_black(int idx, int ans) {
    ans_black = max(ans, ans_black);

    for (int i = idx; i < one.size(); i++) { // N번째부터 시작하는 모든 경우의 수 확인
        int now_x = one[i].first;
        int now_y = one[i].second;

        // 놓을 수 있는 좌표가 체스판에서 검은색 칸인지 확인
        if (now_x % 2 == 0 && now_y % 2 != 0) continue;
        if (now_x % 2 == 1 && now_y % 2 != 1) continue;

        // 한 번도 놓지 않았고, 대각선 자리에 비숍이 없다면 그 자리에 놓는다.
        if (!check[now_x][now_y] && is_possible(now_x, now_y)) {
            check[now_x][now_y] = true;
            dfs_black(i + 1, ans + 1); // 놓을 수 있는 곳의 다음 인덱스부터 반복한다.
            check[now_x][now_y] = false;
        }
    }
}

void dfs_white(int idx, int ans) {
    ans_white = max(ans, ans_white);

    for (int i = idx; i < one.size(); i++) { // N번째부터 시작하는 모든 경우의 수 확인.
        int now_x = one[i].first;
        int now_y = one[i].second;

        // 놓을 수 있는 좌표가 체스판에서 하얀색 칸인지 확인
        if (now_x % 2 == 0 && now_y % 2 != 1) continue;
        if (now_x % 2 == 1 && now_y % 2 != 0) continue;
        
        // 한 번도 놓지 않았고, 대각선 자리에 비숍이 없다면 그 자리에 놓는다.
        if (!check[now_x][now_y] && is_possible(now_x, now_y)) {
            check[now_x][now_y] = true;
            dfs_white(i + 1, ans + 1); // 놓을 수 있는 곳의 다음 인덱스부터 반복한다.
            check[now_x][now_y] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];

            if (board[i][j] == 1) {
                one.push_back({i, j}); // 계산 가능한 좌표 저장
            }
        }
    }
    
    // 핵심 : 체스 판의 검은 부분과 하얀 부분의 비숍은 절대 만날 수 없다.
    dfs_black(0, 0);
    dfs_white(0, 0);

    cout << ans_black + ans_white;
    
    return 0;
}