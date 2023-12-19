#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int M;

bool DP[31][15001];

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    DP[0][0] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 15000; j++) {
            if (DP[i][j]) {
                DP[i + 1][j + save[i]] = true;
                DP[i + 1][j] = true;
                DP[i + 1][abs(j - save[i])] = true;
            }
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;

        if (temp > 15000) {
            cout << 'N' << ' ';
        }
        else if (DP[N][temp]) {
            cout << 'Y' << ' ';
        }
        else {
            cout << 'N' << ' ';
        }
    }

    return 0;
}