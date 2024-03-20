#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool status[4][8];
int K;

void move(int num, int order) {
    if (order == 1) {
        int save = status[num][7];
        for (int j = 6; j >= 0; j--) {
            status[num][j + 1] = status[num][j];
        }
        status[num][0] = save;
    }
    else {
        int save = status[num][0];
        for (int j = 1; j <= 7; j++) {
            status[num][j - 1] = status[num][j];
        }
        status[num][7] = save;
    }
}

bool connected(int a, int b) {
    if (status[a][2] != status[b][6]) return true;
    else return false;
}

int main() {
    FastIO

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            status[i][j] = s[j] - '0';
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++) {
        int num, order;
        cin >> num >> order;
        num--;

        bool chk1 = connected(0, 1);
        bool chk2 = connected(1, 2);
        bool chk3 = connected(2, 3);

        if (num == 0) {
            move(0, order);
            if (chk1) {
                move(1, -order);
                if (chk2) {
                    move(2, order);
                    if (chk3) {
                        move(3, -order);
                    }
                }
            }
        }
        else if (num == 1) {
            move(1, order);
            if (chk1) move(0, -order);
            if (chk2) {
                move(2, -order);
                if (chk3) {
                    move(3, order);
                }
            }
        }
        else if (num == 2) {
            move(2, order);
            if (chk3) move(3, -order);
            if (chk2) {
                move(1, -order);
                if (chk1) {
                    move(0, order);
                }
            }
        }
        else {
            move(3, order);
            if (chk3) {
                move(2, -order);
                if (chk2) {
                    move(1, order);
                    if (chk1) {
                        move(0, -order);
                    }
                }
            }
        }
    }

    cout << status[0][0] + 2 * status[1][0] + 4 * status[2][0] + 8 * status[3][0];

    return 0;
}