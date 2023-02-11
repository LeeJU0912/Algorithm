#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long N;
    cin >> N;

    long long cube[6];
    long long filter[8][3] = {{0, 1, 2},
                              {0, 1, 3},
                              {0, 2, 4},
                              {0, 3, 4},
                              {5, 1, 2},
                              {5, 1, 3},
                              {5, 2, 4},
                              {5, 3, 4}};

    long long one = INT_MAX;
    long long two = INT_MAX;
    long long three = INT_MAX;
    long long five = 0;

    for (int i = 0; i < 6; i++) {
        cin >> cube[i];
        one = min(one, cube[i]);
        five += cube[i];
    }

    five -= *max_element(cube, cube + 6);

    if (N == 1) {
        cout << five;
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (i == 0 && j == 5 || i == 1 && j == 4 || i == 2 && j == 3) continue;
            two = min(two, cube[i] + cube[j]);
        }
    }

    for (int i = 0; i < 8; i++) {
        three = min(three, cube[filter[i][0]] + cube[filter[i][1]] + cube[filter[i][2]]);
    }

    cout << three * 4 + two * ((N - 2) * 4 + (N - 1) * 4) + one * ((N - 2) * (N - 2) + (N - 2) * (N - 1) * 4);



    return 0;
}