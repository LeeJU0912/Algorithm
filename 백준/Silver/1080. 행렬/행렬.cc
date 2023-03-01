#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;
int matrix[51][51];
int todo[51][51];

void flip(int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[x + i][y + j]) {
                matrix[x + i][y + j] = 0;
            }
            else {
                matrix[x + i][y + j] = 1;
            }
        }
    }
}

bool chk() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] != todo[i][j]) return true;
        }
    }
    return false;
}

int main() {
    FastIO
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] == '1') {
                matrix[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.length(); j++) {
            if (temp[j] == '1') {
                todo[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (matrix[i][j] != todo[i][j]) {
                ans++;
                flip(i, j);
            }
        }
    }
    
    if (chk()) {
        cout << -1;
        return 0;
    }

    cout << ans;


    return 0;
}