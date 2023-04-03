#include <bits/stdc++.h>
using namespace std;

int n, m;
int matrix[1001][1001];
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            matrix[i][j + 1] = s[j] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = min(matrix[i - 1][j - 1], min(matrix[i][j - 1], matrix[i - 1][j])) + 1;
                ans = max(ans, matrix[i][j]);
            }
        }
    }

    cout << ans * ans;

    return 0;
}