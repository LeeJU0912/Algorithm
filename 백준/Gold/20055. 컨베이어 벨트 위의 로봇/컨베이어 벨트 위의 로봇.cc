#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
int board[201];
pair<int, bool> now[201];

void robot_remove() {
    if (now[N].second) now[N].second = false;
}

void belt_moving() {
    pair<int, bool> temp = now[N * 2];
    for (int i = N * 2; i > 1; i--) {
        now[i] = now[i - 1];
    }
    now[1] = temp;

    robot_remove();
}

void robot_moving() {
    for (int i = N; i > 1; i--) {
        if (now[i].second || !now[i].first) continue;
        if (!now[i - 1].second) continue;
        now[i].second = now[i - 1].second;
        now[i - 1].second = false;
        now[i].first--;
    }

    robot_remove();
}

void robot_create() {
    if (now[1].first) {
        now[1].second = true;
        now[1].first--;
    }
}

bool chk_zero() {
    int count = 0;
    for (int i = 1; i <= N * 2; i++) {
        if (now[i].first == 0) count++;
    }

    return count < K;
}

void moving() {
    belt_moving();
    robot_moving();
    robot_create();
}

int main() {
    FastIO

    cin >> N >> K;
    for (int j = 1; j <= N * 2; j++) {
        cin >> board[j];
        now[j] = {board[j], false};
    }

    int ans = 0;
    while(chk_zero()) {
        ans++;

        moving();
    }

    cout << ans;

    return 0;
}