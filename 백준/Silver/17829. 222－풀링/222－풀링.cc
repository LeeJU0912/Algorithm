#include <bits/stdc++.h>
using namespace std;

int n;
int ans;

void solve(vector<vector<int>> board, int t) {
    vector<vector<int>> result(t / 2, vector<int>(t / 2));

    for (int i = 0; i < t; i += 2) {
        for (int j = 0; j < t; j += 2) {
            vector<int> second;
            for (int k = i; k < i + 2; k++) {
                for (int l = j; l < j + 2; l++) {
                    second.push_back(board[k][l]);
                }
            }
            sort(second.begin(), second.end());
            result[i / 2][j / 2] = second[2];
        }
    }

    if (t == 2) {
        ans = result[0][0];
        return;
    }
    solve(result, t / 2);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve(board, n);

    cout << ans;

    return 0;
}