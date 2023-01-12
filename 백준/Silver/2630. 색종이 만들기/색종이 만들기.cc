#include <bits/stdc++.h>
using namespace std;

int N;

int paper[129][129];

int blue;
int white;

void solve(int x, int y, int multi) {
    if (multi == 0) return;
    int counter = 0;
    for (int i = x; i < x + multi; i++) {
        for (int j = y; j < y + multi; j++) {
            if (paper[i][j] == 1) counter++;
        }
    }
    if (counter == multi * multi) blue++;
    else if (counter == 0) {
        white++;
    }
    else {
        solve(x, y, multi / 2);
        solve(x + multi / 2, y, multi / 2);
        solve(x, y + multi / 2, multi / 2);
        solve(x + multi / 2, y + multi / 2, multi / 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    solve(0, 0, N);

    cout << white << '\n' << blue;

    return 0;
}