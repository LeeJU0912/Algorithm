#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    char board[100][100];

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int counter;

    int ans1 = 0;
    for (int i = 0; i < N; i++) {
        counter = 0;
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'X') {
                if (counter >= 2) {
                    ans1++;
                }
                counter = 0;
            }
            else {
                counter++;
            }
        }
        if (counter >= 2) {
            ans1++;
        }
    }


    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        counter = 0;
        for (int j = 0; j < N; j++) {
            if (board[j][i] == 'X') {
                if (counter >= 2) {
                    ans2++;
                }
                counter = 0;
            }
            else {
                counter++;
            }
        }
        if (counter >= 2) {
            ans2++;
        }
    }

    cout << ans1 << ' ' << ans2;

    return 0;
}