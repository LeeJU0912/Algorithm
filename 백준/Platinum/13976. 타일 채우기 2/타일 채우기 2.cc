#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

#define MOD 1000000007

typedef vector<vector<long long>> matrix;

long long N;

matrix X = {
        {4, -1},
        {1, 0}
};

matrix Y = {
        {1, 0},
        {0, 1}
};

matrix operator * (matrix &a, matrix &b) {
    matrix c(2, vector<long long>(2));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += (a[i][k] * b[k][j]) % MOD;
                c[i][j] = (c[i][j] + MOD) % MOD;
           }
        }
    }

    return c;
}

int main() {
    FastIO

    cin >> N;

    if (N % 2) {
        cout << 0;
    }
    else {
        long long counter = N / 2;

        while(counter) {
            if (counter & 1) {
                Y = Y * X;
            }

            X = X * X;
            counter >>= 1;
        }

        matrix ans = {
                {1, 0},
                {1, 0}
        };

        cout << (Y * ans)[0][0];
    }

    return 0;
}