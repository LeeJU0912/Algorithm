#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> color[5001];

int ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        color[b].push_back(a);
    }

    for (int i = 1; i <= 5000; i++) {
        if (color[i].empty()) continue;

        sort(color[i].begin(), color[i].end());

        for (int j = 0; j < color[i].size(); j++) {
            int temp = 0;

            if (j == 0) temp += color[i][j + 1] - color[i][j];
            else if (j == color[i].size() - 1) temp += color[i][j] - color[i][j - 1];
            else {
                int gap_before = color[i][j] - color[i][j - 1];
                int gap_after = color[i][j + 1] - color[i][j];
                if (gap_after > gap_before) {
                    temp += gap_before;
                }
                else {
                    temp += gap_after;
                }
            }

            ans += temp;
        }
    }

    cout << ans;

    return 0;
}