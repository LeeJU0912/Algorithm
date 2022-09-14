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

using namespace std;

char graph[11][11];
int check[11][11];
int cpy_check[11][11];
int answer = INT_MAX;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int all_dark() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (cpy_check[i][j]) return 0;
        }
    }
    return 1;
}

void change(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
            cpy_check[nx][ny] = !cpy_check[nx][ny];
        }
    }
    cpy_check[x][y] = !cpy_check[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'O') check[i][j] = 1;
        }
    }

    // 1 << 10 = 1024 = 10000000000 !이진수로 한 줄의 경우의 수 표기!
    for (int first_line = 0; first_line < (1 << 10); first_line++) {
        int counter = 0;
        for (int j = 0; j < 10; j++) { // 매 경우의 수 마다 배열 카피 후 비교
            for (int k = 0; k < 10; k++) {
                cpy_check[j][k] = check[j][k];
            }
        }

        for (int bit = 0; bit < 10; bit++) { // 첫째줄 우선 비교
            // (첫째줄 켜진 상태) and연산 (1 << bit) 둘 다 1일 경우에만 1로 표기. 해당 위치를 눌러야 하는지 체크하는 방법.
            if (first_line & (1 << bit)) {
                change(0, bit); // x, y 점을 중심으로 바꾼다.
                counter++;
            }
        }

        for (int column = 1; column < 10; column++) { // 윗줄의 점을 기준으로 시행한다.
            for (int bit = 0; bit < 10; bit++) {
                if (cpy_check[column - 1][bit]) { // 바로 위에 점이 켜져 있다면 무조건 꺼야함.
                    change(column, bit);
                    counter++;
                }
            }
        }

        if (all_dark()) answer = min(counter, answer);
    }

    if (answer == INT_MAX) {
        cout << -1;
    }
    cout << answer;

    return 0;
}