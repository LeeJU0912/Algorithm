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

int N;
int list[26][26];
int visited[26][26];
int counter;
int ans[1000000];
int answer;

void solve(int x, int y) {
    if (x == -1 || y == -1 || x == N || y == N) return;
    if (list[x][y] == 0 || visited[x][y] == 1) {
        return;
    }
    visited[x][y] = 1;
    ans[counter]++;

    solve(x - 1, y);
    solve(x + 1, y);
    solve(x, y - 1);
    solve(x, y + 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            list[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            solve(i, j);
            counter++;
        }
    }

    for (int i = 0; i < counter; i++) {
        if (ans[i] == 0) continue;
        answer++;
    }
    cout << answer << '\n';

    sort(ans, ans + counter);

    for (int i = 0; i < counter; i++) {
        if (ans[i] == 0) continue;
        cout << ans[i] << '\n';
    }


    return 0;
}