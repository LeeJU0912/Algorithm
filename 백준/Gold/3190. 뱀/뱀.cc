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
#include <list>

using namespace std;

int board[101][101];
int N;
int K;
int L;

int current_go = 1;
map<int, char> mp;

int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

int elapsed;

void solve() {
    deque<pair<int, int>> q;
    q.push_back({1, 1});
    board[1][1] = 2;

    while(!q.empty()) {
        int now_x = q.back().first;
        int now_y = q.back().second;


        if (mp.count(elapsed)) {
            if (mp[elapsed] == 'L') {
                current_go++;
                if (current_go == 4) {
                    current_go = 0;
                }
            }
            else if (mp[elapsed] == 'D') {
                current_go--;
                if (current_go == -1) {
                    current_go = 3;
                }
            }
        }

        elapsed++;

        int next_x = now_x + dx[current_go];
        int next_y = now_y + dy[current_go];

        if (next_x > N || next_x <= 0 || next_y > N || next_y <= 0) {
            return;
        }
        if (board[next_x][next_y] == 2) {
            return;
        }
        if (board[next_x][next_y] == 1) {
            board[next_x][next_y] = 2;
            q.push_back({next_x, next_y});
        }
        else if (board[next_x][next_y] == 0) {
            board[next_x][next_y] = 2;
            q.push_back({next_x, next_y});
            board[q.front().first][q.front().second] = 0;
            q.pop_front();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        int a;
        char b;
        cin >> a >> b;

        mp.insert({a, b});
    }

    solve();
    
    cout << elapsed;


    return 0;
}