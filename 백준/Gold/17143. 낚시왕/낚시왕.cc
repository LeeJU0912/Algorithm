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

int R, C, M;

struct Shark_info {
    int R;
    int C;
    int Speed;
    int Rot;
    int Size;
    int idx;
};
vector<Shark_info> Shark;
vector<int> board[101][101];
int ans;

void print_board() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].empty()) {
                cout << 0 << " \n"[j == C];
            }
            else {
                cout << Shark[board[i][j][0] - 1].Size << " \n"[j == C];
            }
        }
    }
    cout << '\n';
}

void fishing(int start) {
    for (int i = 1; i <= R; i++) {
        if (!board[i][start].empty()) {
            auto x = Shark[board[i][start][0] - 1];
            ans += x.Size;

            board[i][start].clear();
            return;
        }
    }
}

void moving() {
    queue<int> q;
    for (auto i : Shark) {
        if (!board[i.R][i.C].empty()) {
            if (board[i.R][i.C][0] == i.idx) {
                q.push(i.idx);
            }
        }
    }

    while (!q.empty()) {
        auto &i = Shark[q.front() - 1];
        int temp = board[i.R][i.C][0];
        board[i.R][i.C].erase(board[i.R][i.C].begin());


        if (i.Rot == 1) {
            i.R -= i.Speed;
        }
        else if (i.Rot == 2) {
            i.R += i.Speed;
        }
        else if (i.Rot == 3) {
            i.C += i.Speed;
        }
        else if (i.Rot == 4) {
            i.C -= i.Speed;
        }

        while(i.R <= 0 || i.R > R || i.C <= 0 || i.C > C) {
            if (i.Rot == 1) {
                i.R = 1 + abs(i.R) + 1;
                i.Rot = 2;
            }
            else if (i.Rot == 2) {
                i.R = R - i.R + R;
                i.Rot = 1;
            }
            else if (i.Rot == 3) {
                i.C = C - i.C + C;
                i.Rot = 4;
            }
            else if (i.Rot == 4) {
                i.C = 1 + abs(i.C) + 1;
                i.Rot = 3;
            }
        }

        board[i.R][i.C].push_back(temp);
        q.pop();

    }



    for (auto i : Shark) {
        int maxi = 0;
        int idx = 0;
        if (board[i.R][i.C].size() > 1) {
            for (int j = 0; j < board[i.R][i.C].size(); j++) {
                if (Shark[board[i.R][i.C][j] - 1].Size > maxi) {
                    maxi = Shark[board[i.R][i.C][j] - 1].Size;
                    idx = j;
                }
            }
            int temp = board[i.R][i.C][idx];
            board[i.R][i.C].clear();
            board[i.R][i.C].push_back(temp);
        }
    }
}

void solve(int start) {
    //print_board();
    fishing(start);
    moving();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C >> M;

    for (int i = 1; i <= M; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        Shark.push_back({a, b, c, d, e, i});
        board[a][b].push_back(i);
    }

    for (int i = 1; i <= C; i++) {
        solve(i);
    }

    cout << ans;

    return 0;
}