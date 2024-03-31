#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int cube[6][9];
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};

void init_cube() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 9; j++) {
            cube[i][j] = i;
        }
    }
}

void turn_front(int n, int order) {
    int temp[9];
    for (int i = 0; i < 9; i++) {
        temp[i] = cube[n][i];
    }
    if (order) {
        cube[n][2] = temp[0];
        cube[n][5] = temp[1];
        cube[n][8] = temp[2];
        cube[n][1] = temp[3];
        cube[n][4] = temp[4];
        cube[n][7] = temp[5];
        cube[n][0] = temp[6];
        cube[n][3] = temp[7];
        cube[n][6] = temp[8];
    }
    else {
        cube[n][6] = temp[0];
        cube[n][3] = temp[1];
        cube[n][0] = temp[2];
        cube[n][7] = temp[3];
        cube[n][4] = temp[4];
        cube[n][1] = temp[5];
        cube[n][8] = temp[6];
        cube[n][5] = temp[7];
        cube[n][2] = temp[8];
    }
}

void turn(int n, bool order) {
    turn_front(n, order);
    int side[4][3];

    if (n == 0) {
        for (int i = 0; i < 3; i++) {
            side[0][i] = cube[2][i];
            side[1][i] = cube[4][i];
            side[2][i] = cube[3][i];
            side[3][i] = cube[5][i];
        }

        if (order) {
            for (int i = 0; i < 3; i++) {
                cube[4][i] = side[0][i];
                cube[3][i] = side[1][i];
                cube[5][i] = side[2][i];
                cube[2][i] = side[3][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                cube[5][i] = side[0][i];
                cube[3][i] = side[3][i];
                cube[4][i] = side[2][i];
                cube[2][i] = side[1][i];
            }
        }
    }
    else if (n == 1) {
        for (int i = 0; i < 3; i++) {
            side[0][i] = cube[2][i + 6];
            side[1][i] = cube[5][i + 6];
            side[2][i] = cube[3][i + 6];
            side[3][i] = cube[4][i + 6];
        }

        if (order) {
            for (int i = 0; i < 3; i++) {
                cube[5][i + 6] = side[0][i];
                cube[3][i + 6] = side[1][i];
                cube[4][i + 6] = side[2][i];
                cube[2][i + 6] = side[3][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                cube[4][i + 6] = side[0][i];
                cube[3][i + 6] = side[3][i];
                cube[5][i + 6] = side[2][i];
                cube[2][i + 6] = side[1][i];
            }
        }
    }
    else if (n == 2) {
        for (int i = 0; i < 3; i++) {
            side[0][i] = cube[0][i + 6];
            side[1][i] = cube[5][i * 3];
            side[2][i] = cube[1][2 - i];
            side[3][i] = cube[4][8 - i * 3];
        }

        if (order) {
            for (int i = 0; i < 3; i++) {
                cube[5][i * 3] = side[0][i];
                cube[1][2 - i] = side[1][i];
                cube[4][8 - i * 3] = side[2][i];
                cube[0][i + 6] = side[3][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                cube[4][8 - i * 3] = side[0][i];
                cube[1][2 - i] = side[3][i];
                cube[5][i * 3] = side[2][i];
                cube[0][i + 6] = side[1][i];
            }
        }
    }
    else if (n == 3) {
        for (int i = 0; i < 3; i++) {
            side[0][i] = cube[0][2 - i];
            side[1][i] = cube[4][i * 3];
            side[2][i] = cube[1][i + 6];
            side[3][i] = cube[5][8 - i * 3];
        }

        if (order) {
            for (int i = 0; i < 3; i++) {
                cube[4][i * 3] = side[0][i];
                cube[1][i + 6] = side[1][i];
                cube[5][8 - i * 3] = side[2][i];
                cube[0][2 - i] = side[3][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                cube[5][8 - i * 3] = side[0][i];
                cube[1][i + 6] = side[3][i];
                cube[4][i * 3] = side[2][i];
                cube[0][2 - i] = side[1][i];
            }
        }
    }
    else if (n == 4) {
        for (int i = 0; i < 3; i++) {
            side[0][i] = cube[0][i * 3];
            side[1][i] = cube[2][i * 3];
            side[2][i] = cube[1][i * 3];
            side[3][i] = cube[3][8 - i * 3];
        }

        if (order) {
            for (int i = 0; i < 3; i++) {
                cube[2][i * 3] = side[0][i];
                cube[1][i * 3] = side[1][i];
                cube[3][8 - i * 3] = side[2][i];
                cube[0][i * 3] = side[3][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                cube[3][8 - i * 3] = side[0][i];
                cube[1][i * 3] = side[3][i];
                cube[2][i * 3] = side[2][i];
                cube[0][i * 3] = side[1][i];
            }
        }
    }
    else if (n == 5) {
        for (int i = 0; i < 3; i++) {
            side[0][i] = cube[0][8 - i * 3];
            side[1][i] = cube[3][i * 3];
            side[2][i] = cube[1][8 - i * 3];
            side[3][i] = cube[2][8 - i * 3];
        }

        if (order) {
            for (int i = 0; i < 3; i++) {
                cube[3][i * 3] = side[0][i];
                cube[1][8 - i * 3] = side[1][i];
                cube[2][8 - i * 3] = side[2][i];
                cube[0][8 - i * 3] = side[3][i];
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                cube[2][8 - i * 3] = side[0][i];
                cube[1][8 - i * 3] = side[3][i];
                cube[3][i * 3] = side[2][i];
                cube[0][8 - i * 3] = side[1][i];
            }
        }
    }
}

int main() {
    FastIO

    int T;
    cin >> T;
    while(T--) {
        init_cube();

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            bool plus = false;

            if (s[1] == '+') {
                plus = true;
            }

            if (s[0] == 'U') {
                turn(0, plus);
            }
            else if (s[0] == 'D') {
                turn(1, plus);
            }
            else if (s[0] == 'F') {
                turn(2, plus);
            }
            else if (s[0] == 'B') {
                turn(3, plus);
            }
            else if (s[0] == 'L') {
                turn(4, plus);
            }
            else if (s[0] == 'R') {
                turn(5, plus);
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 3; j++) {
                cout << color[cube[0][i + j]];
            }
            cout << '\n';
        }
    }

    return 0;
}