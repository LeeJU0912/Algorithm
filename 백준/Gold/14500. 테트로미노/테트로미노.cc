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

int N, M;
int paper[501][501];
int ans;

void solve() {
    // 네모
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1]);
        }
    }
    // 짝대기(가로)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 3; j++) {
            ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3]);
        }
    }
    // 짝대기(세로)
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < M; j++) {
            ans = max(ans, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j]);
        }
    }
    // 번개(가로)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2]);
        }
    }
    // 번개(세로)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);
        }
    }
    // 번개(가로 - 뒤집기)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
        }
    }
    // 번개(세로 - 뒤집기)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j] + paper[i + 2][j]);
        }
    }
    // 기역(1)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1]);
        }
    }
    // 기역(1 - 뒤집기)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 2][j]);
        }
    }
    // 기역(2)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);
        }
    }
    // 기역(2 - 뒤집기)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j]);
        }
    }
    // 기역(3)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2] + paper[i][j + 2]);
        }
    }
    // 기역(3 - 뒤집기)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2]);
        }
    }
    // 기역(4)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i + 1][j] + paper[i][j] + paper[i][j + 1] + paper[i][j + 2]);
        }
    }
    // 기역(4 - 뒤집기)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2]);
        }
    }
    // ㅗ(1)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1]);
        }
    }
    // ㅗ(1 - 뒤집기)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            ans = max(ans, paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2] + paper[i][j + 1]);
        }
    }
    // ㅗ(2)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j + 1]);
        }
    }
    // ㅗ(2 - 뒤집기)
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 1; j++) {
            ans = max(ans, paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
        }
    }

    solve();

    cout << ans;

    return 0;
}